#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

typedef char byte;
typedef class {
public:
    byte board[20][20];
} gameBoard;

int n;
bool findBlock[21];
gameBoard initBoard;
queue<gameBoard> twoZeroFourEight;

void play2048() {
    // BFS pruning
    gameBoard nowBoard, tempBoard;
    twoZeroFourEight.push(initBoard);
    while(!twoZeroFourEight.empty()) {
        nowBoard = twoZeroFourEight.front();
        twoZeroFourEight.pop();

        // 우측으로 
        memcpy(tempBoard.board, nowBoard.board, sizeof(gameBoard));
        for(int i=0;i<n;++i) {
            for(int j=n-1;j>=1;--j) {
                if(tempBoard.board[i][j] == tempBoard.board[i][j-1]) {
                    tempBoard.board[i][j] ++;
                    tempBoard.board[i][j-1] = 0;
                }
            }
        }
        twoZeroFourEight.push(tempBoard);
        
        // 좌측으로
        memcpy(tempBoard.board, nowBoard.board, sizeof(gameBoard));
        twoZeroFourEight.push(tempBoard);
        
        // 위로
        memcpy(tempBoard.board, nowBoard.board, sizeof(gameBoard));
        twoZeroFourEight.push(tempBoard);
        
        // 아래로
        memcpy(tempBoard.board, nowBoard.board, sizeof(gameBoard));
        twoZeroFourEight.push(tempBoard);
        
    }

    // 결과 출력
    for(int i=20;i>=0;--i) {
        if(findBlock[i]) {
            cout << int(pow(2.0, double(i)));
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int temp;
    memset(findBlock, 0, sizeof(findBlock));
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cin >> temp;
            temp = int(log2(double(temp)));
            initBoard.board[i][j] = temp;
            findBlock[temp] = true;
        }
    }

    play2048();
    return 0;
}