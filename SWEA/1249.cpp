#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
char mymap[101][101];
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > wheretogo;
int cost[101][101];
const int dx[] = {+1, 0, -1, 0};
const int dy[] = {0, +1, 0, -1};
const int my_inf = 123456789;

inline bool in_range(int current, int criteria){
    if(current >= 0 && current < criteria){ 
        return true;
    }
    else { 
        return false;
    }
}

inline int c2i(char c){
    if(c >= '0' && c <= '9'){
        return int(c - '0');
    }
    else {
        return -1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for(int t=1;t<=T;++t){
        // initialize cost arrary
        for(int i=0;i<100;++i){
            for(int j=0;j<100;++j){
                cost[i][j] = my_inf;
            }
        }
        cost[0][0] = 0;

        // clear priority_queue
        while(!wheretogo.empty()){
            wheretogo.pop();
        }

        // data input
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> mymap[i];
        }

        // first push to queue
        wheretogo.push({0, {0, 0}});
        pair<int, pair<int, int> > now;
        int now_x, now_y, next_x, next_y;

        while(!wheretogo.empty()){
            // get minimum value
            now = wheretogo.top();
            wheretogo.pop();
            now_x = now.second.first;
            now_y = now.second.second;
//            cost[now_x][now_y] = now.first;
            if(cost[now_x][now_y] < now.first){ continue;}

            // search four directions
            for(int i=0;i<4;++i){
                next_x = now.second.first + dx[i];
                next_y = now.second.second + dy[i];

                if(in_range(next_x, n) && in_range(next_y, n)){
                    if(cost[now_x][now_y] + c2i(mymap[next_x][next_y]) < cost[next_x][next_y]){
                        wheretogo.push({cost[now_x][now_y] + c2i(mymap[next_x][next_y]), {next_x, next_y}});
                        cost[next_x][next_y] = cost[now_x][now_y] + c2i(mymap[next_x][next_y]);
                    }
                }
            }
        }

        cout << '#' << t << ' ' << cost[n-1][n-1] << '\n';/*
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout << cost[i][j] << ' ';
            }
            cout << '\n';
        }*/
    }
    return 0;
}