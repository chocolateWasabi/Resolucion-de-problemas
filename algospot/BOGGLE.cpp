// algospot 첫 문제 - ch6 완전탐색 단원이지만 DP...? 인지는 모르겠고
// 아무튼 메모이제이션(cache)을 해야 하는 문제. (AC)
#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
int dy[] = {0, +1, +1, +1, 0, -1, -1, -1};

char board[6][6], target[11];
int cache[6][6][8];
void search(int x, int y, int level, int& if_find){
    if(level == strlen(target) - 1){
        if_find = 1;
        return;
    }/*
    if(level == 10 + 1){
        return false;
    }*/
    for(int i=0;i<8;++i){
        if(cache[x][y][i] != 1){ // 잘못된 경로를 찍어놓았는데, 다시 가지 않도록만 처리!
            if(x+dx[i] >=0 && x+dx[i] < 5 && y+dy[i] >= 0 && y+dy[i] < 5){
                if(board[x+dx[i]][y+dy[i]] == target[level+1]){
                    //cache[x][y][i] = 0; // assuming valid path - 뻘짓. 무시.
                    search(x+dx[i], y+dy[i], level+1, if_find);
                    cache[x][y][i] = 1; // invalid path
                }
            }
        }
    }
    //return 0;
}

int main(){
    //ios_base::sync_with_stdio(false); - algospot은 이거 필요 없는 듯.
    //cin.tie(NULL);
    int C, n;
    int result;
    cin >> C;
    for(int t=1;t<=C;++t){
        for(int i=0;i<5;++i) cin >> board[i];
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> target;
            result = 0;
            for(int x=0;x<5 && !result;++x){
                for(int y=0;y<5 && !result;++y){
                    if(board[x][y] == target[0]){
                        memset(cache, 0, sizeof(cache));
                        // 이 cache 초기화를 매번 보낼 때마다 해주어야 한다.
                        // 시작하는 포지션이 달라지기 때문에...
                        // 이전 위치에서 시작했을 때 검색하던 경로와 무관하게
                        // 해주어야 하나 보다.
                        search(x, y, 0, result);
                        //cout << result;
                    }
                }
            }
            cout << target << (result? " YES\n": " NO\n");
        }
    }
    return 0;
}

// boolean type으로 하면 255가 나오는 현상...? - Notion 에 따로 정리하기.