// Basic implementation of DFS and BFS
// BOJ ID 2606
#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int v, e;
int net[101][101];
int visit[101];

void dfs(int now_v, int level){
    visit[now_v] = level;
    for(int i=1;i<=v;++i){
        if(!visit[i] && net[now_v][i]){
            dfs(i, level+1);
        }
    }
}

void bfs(queue<pair<int, int> >& next_visit){
    pair<int, int> now_info;
    
    while(!next_visit.empty()){
        now_info = next_visit.front();
        next_visit.pop();

        for(int i=1;i<=v;++i){
            if(!visit[i] && net[now_info.first][i]){
                visit[i] = now_info.second + 1;
                next_visit.push({i, visit[i]});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> v >> e;
    for(int i=1, a, b;i<=e;++i){
        cin >> a >> b;
        net[a][b] = net[b][a] = 1;
    }

    visit[1] = 1;
    dfs(1, 1);
    
    
    cout << "DFS\n";
    for(int i=1;i<=v;++i){
        cout << i << ':' << visit[i] << '\n';
    }
    cout << '\n';
    memset(visit, 0, sizeof(visit));

    visit[1] = 1;
    queue<pair<int, int> > next_visit;
    next_visit.push({1, 1});
    bfs(next_visit);
    

    cout << "BFS\n";
    for(int i=1;i<=v;++i){
        cout << i << ':' << visit[i] << '\n';
    }

    int count = 0;
    for(int i=1;i<=v;++i){
        if(visit[i]){
            count ++;
        }
    }
    cout << count - 1;
    return 0;
}