#include <iostream>
#include <cstring>
using namespace std;

int H, W;
char board[25][25];

int dx[] = {+1, +1, +1, -1, -1, -1, 0, 0};
int dy[] = {-1, 0, +1, -1, 0, +1, -1, +1};
int bricks[][2] = {{7, 1}, {7, 2}, {1, 2}, {1, 0}};

int final;

void wheretogo(int &x, int &y, bool &nowheretogo){
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(board[i][j] == '.'){
                x = i;
                y = j;
                return;
            }
        }
    }
    nowheretogo = true;
}

bool valid(int x, int y){
    if(x >= 0 && x < H && y >=0 && y < W){
        return board[x][y] == '.'? true: false;
    }   
    return false;
}

void print_board(){
    cout << endl;
    for(int i=0;i<H;++i){
        cout << board[i] << endl;
    }
    
}

int kkk = 0;
void cover(int x, int y, int& count){
    /*if(final == finalcheck){
        count ++;
        return;
    }*/
    int x2, y2, x3, y3;
    int tx, ty;
    bool nowheretogo;
    for(int i=0;i<4;++i){
        x2 = x + dx[bricks[i][0]];
        y2 = y + dy[bricks[i][0]];
        x3 = x + dx[bricks[i][1]];
        y3 = y + dy[bricks[i][1]];

        if(valid(x2, y2) && valid(x3, y3)){
            board[x][y] = board[x2][y2] = board[x3][y3] = char(kkk+'0');
            kkk++;
            // tx = x, ty = y;
            nowheretogo = false;
            wheretogo(tx, ty, nowheretogo);

            if(!nowheretogo){
                //print_board();
                cover(tx, ty, count);
            }

            kkk--;
            board[x][y] = board[x2][y2] = board[x3][y3] = '.';

            if(nowheretogo){ // 기저 사례의 위치가 조금 특이.
                count ++;
                return;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;

    cin >> C;

    int x, y, count;
    bool nowheretogo;
    for(int c=1;c<=C;++c){
        cin >> H >> W;
        memset(board, 0, sizeof(board));
        final = 0;
        for(int i=0;i<H;++i){
            cin >> board[i];
            for(int j=0;j<W;++j){
                if(board[i][j] == '.'){
                    final ++;
                }
            }
        }

        count = 0;
        nowheretogo = false;
        x = y = 0;
        wheretogo(x, y, nowheretogo);

        if(!nowheretogo){
            cover(x, y, count); 
            cout << count << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}