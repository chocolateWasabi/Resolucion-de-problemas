#include <iostream>
using namespace std;

int chess[16][16];
int dx[] = {-1, -1, -1, +1, +1, +1, 0, 0};
int dy[] = {-1, 0, +1, -1, 0, +1, -1, +1};

void draw(int x, int y, int n, int value){
    for(int i=1;i<=n;++i){
        for(int j=0;j<8;++j){
            if(x+i*dx[j] >= 1 && x+i*dx[j] <= n && y+i*dy[j] >= 1 && y+i*dy[j] <= n){
                chess[x+i*dx[j]][y+i*dy[j]] += value;
            }
        }
    }
}

void nqueen(int column, int n, int& cases){
    if(column == n + 1){
        cases ++;
        return;
    }
    for(int i=1;i<=n;++i){
        if(chess[i][column] == 0){
            chess[i][column] = 1;
            draw(i, column, n, 1); // 퀸 하나 놓일 때마다 +1
            nqueen(column+1, n, cases);
            draw(i, column, n, -1); // 퀸 빼면 -1 (0으로 하면 다른 퀸에 의한 요소에 영향)
            chess[i][column] = 0;
        }
    }
}

int main(){
    int n;
    cin >> n;

    int cases = 0;
    nqueen(1, n, cases);

    cout << cases;
    return 0;
}