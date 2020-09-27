/*
// BOJ ID 12865
#include <iostream>
#include <cstring>
#define max_weight 100010
using namespace std;

int n, k;
int weight_value_info[2][max_weight];

int min(int a, int b){
    return a > b? a: b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(weight_value_info, 0, sizeof(weight_value_info));

    int n, k;
    cin >> n >> k;
    int flag = 0;
    for(int i=1;i<=n;++i){
        int w, v;
        cin >> w >> v;
        flag ^= 1;
        for(int j=1;j<w;++j){
            weight_value_info[flag][j] = weight_value_info[flag^1][j];
        }
        for(int j=w;j<=k;++j){
            weight_value_info[flag][j] = max(weight_value_info[flag^1][j], weight_value_info[flag^1][j-w]+v);
        }/*
        for(int j=1;j<=k;++j){
            cout << weight_value_info[flag][j] << ' ';
        }
        cout << endl;
    }
    cout << weight_value_info[flag][k];
    return 0;
}
*/
/*
// BOJ ID 9251 (review)
#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b){
    return a > b? a: b;
}

int main(){
    char dat[2][1001];
    cin >> dat[0] >> dat[1];
    int len[2];
    len[0] = strlen(dat[0]), len[1] = strlen(dat[1]);
    int crit = len[0] <= len[1]? 0: 1;
    int check[2][1001];
    memset(check, 0, sizeof(check));
    int current_max, flag = 0;
    for(int i=0;i<len[crit];++i){
        current_max = 0;
        flag ^= 1;
        for(int j=0;j<len[crit^1];++j){
            if(dat[crit^1][j] == dat[crit][i]){
                check[flag][j] = max(check[flag^1][j], current_max + 1);
            }
            else{
                check[flag][j] = check[flag^1][j];
            }
            current_max = check[flag^1][j] > current_max? check[flag^1][j]: current_max;
        }
    }
    current_max = 0;
    for(int i=0;i<len[crit^1];++i){
        current_max = check[flag][i] > current_max? check[flag][i]: current_max;
    }
    cout << current_max;
    return 0;
}*/

/*
// BOJ ID 2206
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

char mapp[1001][1001];
int check[1001][1001][2]; // 0 layer = not break , 1 layer = break

bool in_range(int x, int c){
    return x >= 0 && x < c? true: false;
}

const int dx[] = {0, +1, 0, -1};
const int dy[] = {-1, 0, +1, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> mapp[i];
    }

    queue<pair<pair<int, int>, bool> > next; // (x, y), break
    pair<pair<int, int>, int> now;
    
    next.push({{0, 0}, false});
    check[0][0][0] = check[0][0][1] = 1;
    int next_x, next_y;
    int next2_x, next2_y;
    while(!next.empty()){
        now = next.front();
        next.pop();
        //if(now.first.first == n-1 && now.first.second == m-1){
        //    break;
        //}

        for(int i=0;i<4;++i){
            next_x = now.first.first+dx[i];
            next_y = now.first.second+dy[i];
            if(in_range(next_x, n) && in_range(next_y, m) && !check[next_x][next_y][0]){
                if(mapp[next_x][next_y] == '0'){ // normal case
                    if(now.second && check[next_x][next_y][1]){
                        if(check[now.first.first][now.first.second][now.second] + 1 >= check[next_x][next_y][1]){
                            continue;
                        }
                    }
                    next.push({{next_x, next_y}, now.second});
                    check[next_x][next_y][now.second] = check[now.first.first][now.first.second][now.second] + 1;
                }
                else if(mapp[next_x][next_y] == '1' && !now.second){ // break wall
                    
                    for(int j=0;j<4;++j){
                        next2_x = next_x + dx[j];
                        next2_y = next_y + dy[j];
                        if(in_range(next2_x, n) && in_range(next2_y, m) && !check[next2_x][next2_y][0] && mapp[next2_x][next2_y] == '0'){
                            if(!check[next2_x][next2_y][1] || check[next2_x][next2_y][1] && check[now.first.first][now.first.second][0] + 2 < check[next2_x][next2_y][1]){
                                next.push({{next2_x, next2_y}, 1});
                                check[next_x][next_y][1] = check[now.first.first][now.first.second][0] + 1;
                                check[next2_x][next2_y][1] = check[now.first.first][now.first.second][0] + 2;
                            }
                        }
                    }

                }
                else { // error
                }
            }
        }
    }
    while(!next.empty()){
        next.pop();
    }

    if(check[n-1][m-1][0]){
        if(check[n-1][m-1][1]){
            cout << min(check[n-1][m-1][0], check[n-1][m-1][1]);
        }
        else {
            cout << check[n-1][m-1][0];
        }
    }
    else {
        if(check[n-1][m-1][1]){
            cout << check[n-1][m-1][1];
        }
        else {
            cout << -1;
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout << check[i][j][0] << ' ';
        }
        cout << endl;
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout << check[i][j][1] << ' ';
        }
        cout << endl;
    }
    return 0;
}*/

