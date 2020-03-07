#include <iostream>
#include <cstring>
using namespace std;

int dx[] = {-1, -1, 0, +1, +1, +1, 0, -1};
int dy[] = {0, +1, +1, +1, 0, -1, -1, -1};

char board[6][6], target[11];
int search(int x, int y, int level){
    if(level == strlen(target) - 1){
        return 1;
    }/*
    if(level == 10 + 1){
        return false;
    }*/
    for(int i=0;i<8;++i){
        if(x+dx[i] >=0 && x+dx[i] < 5 && y+dy[i] >= 0 && y+dy[i] < 5){
            if(board[x+dx[i]][y+dy[i]] == target[level+1]){
                return search(x+dx[i], y+dy[i], level+1);
            }
        }
    }
    return 0;
}

int main(){
    //ios_base::sync_with_stdio(false);
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
                        result = search(x, y, 0);
                        cout << result;
                    }
                }
            }
            cout << target << (result? " YES\n": " NO\n");
        }
    }
    return 0;
}

// boolean type으로 하면 255가 나오는 현상...?