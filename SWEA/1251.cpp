#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

long long sqr(long long a){
    return a * a;
}

typedef pair<double, long long > pairpair;

double converted[1000][1000];
int visit[1000];
double cost2me[1000];
vector<pair<long long, long long> > mapinfo;
priority_queue<pairpair, vector<pairpair>, greater<pairpair> > mst_edge;

int n;
double e;
double cost;
long long cost2;

void make_mst(){
    mst_edge.push({0, 0});

    while(!mst_edge.empty()){
        pairpair now = mst_edge.top();
        mst_edge.pop();
        if(visit[now.second]){ continue;}
        visit[now.second] = 1;
        cost2me[now.second] = now.first;

        for(int i=0;i<n;++i){
            if(converted[now.second][i] > 0.0 && !visit[i]){
                mst_edge.push({converted[now.second][i], i});
            }
        }
    }

    for(int i=1;i<n;++i){
        cost += (e * cost2me[i] * cost2me[i]);
    }
    cost += 0.5;
    cost2 = (long long)(cost);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        memset(converted, 0, sizeof(converted));
        memset(visit, 0, sizeof(visit));
        memset(cost2me, 0, sizeof(cost2me));
        mapinfo.clear();
        while(!mst_edge.empty()){mst_edge.pop();}
        n = 0;
        cost2 = 0;
        e = cost = 0.0;

        cin >> n;
        int x, y;
        for(int i=0;i<n;++i){
            cin >> x;
            mapinfo.push_back({x, 0});
        }
        for(int i=0;i<n;++i){
            cin >> y;
            mapinfo[i] = {mapinfo[i].first, y};
        }
        cin >> e;

        for(int i=0;i<n;++i){ // 그래프로 다시 구조화
            for(int j=0;j<n;++j){
                converted[i][j] = sqrt((double)(sqr(mapinfo[i].first - mapinfo[j].first) + sqr(mapinfo[i].second - mapinfo[j].second)));
                //cout << converted[i][j] << ' ';
            }
            //cout << '\n';
        }
        make_mst();
        cout << '#' << t << ' ' << cost2 << '\n';
    }
    return 0;
}