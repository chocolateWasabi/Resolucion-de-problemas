// SWEA 1249, 파손된 도로 (Dijkstra 문제)
// S -> G 로 가는 Single-Pair 문제
// 결국 행렬의 모든 요소가 node 라고 생각하면 된다. (CCW 방향 45도 회전하면 이해가 빠름)
// 결국 n 최대가 100이니까 node 수는 100 * 100 = 10000
// ==> 그냥 다 돌리면 무조건 시간 초과... 그래서 지금 TLE 가 떴다.
// 이전의 풀이가 잘못된 이유는, 
// 하/우 움직임만 있었으면 DP 문제, 상/하/좌/우 움직임이 가능하기 때문에 Dijkstra
// 그렇지만 지금의 TLE 가 나는 코드를 수정할 방법을 생각해보자. 
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int n;
char mymap[101][101];
priority_queue<pair<int, pair<int, int> > > wheretogo;
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
            cost[now_x][now_y] = now.first;

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