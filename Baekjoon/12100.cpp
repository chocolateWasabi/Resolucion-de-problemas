#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

typedef char byte;
typedef class {
public:
    byte board[25][25];
    int convergeCount;
} gameBoard;

int n;
bool findBlock[21];
gameBoard initBoard;
queue<gameBoard> twoZeroFourEight;

bool isIdentical(gameBoard& a, gameBoard& b) {
    /*
    bool full, updown, leftright;
    full = updown = leftright = true;
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            // 완전히 같은 경우에 대한 체크
            if(a.board[i][j] != b.board[i][j]) {
                full = false;
            }

            // 상하 대칭인 경우에 대한 체크
            if(a.board[i][j] != b.board[n-i-1][j]) {
                updown = false;
            }

            // 좌우 대칭인 경우에 대한 체크
            if(a.board[i][j] != b.board[i][n-j-1]) {
                leftright = false;
            }
        }
    }
    
    return (full || updown || leftright);*/
    return false;
}

void play2048() {
    // BFS pruning
    gameBoard nowBoard, tempBoard;
    twoZeroFourEight.push(initBoard);
    while(!twoZeroFourEight.empty()) {
        int size = twoZeroFourEight.size();
        nowBoard = twoZeroFourEight.front();
        twoZeroFourEight.pop();

        if(nowBoard.convergeCount >= 5) {
            continue;
        }

        tempBoard.convergeCount = nowBoard.convergeCount + 1;

        // 우측으로 
        memcpy(tempBoard.board, nowBoard.board, sizeof(nowBoard.board));
        for(int i=0;i<n;++i) {
            for(int j=n-1;j>=1;--j) {
                if(tempBoard.board[i][j] != 0 && tempBoard.board[i][j] == tempBoard.board[i][j-1]) {
                    tempBoard.board[i][j] ++;
                    tempBoard.board[i][j-1] = 0;
                    findBlock[tempBoard.board[i][j]] = true;
                }
                if(tempBoard.board[i][j] == 0) { // 0이면 당겨오기
                    for(int k=j-1;k>=0;--k) {
                        tempBoard.board[i][k + 1] = tempBoard.board[i][k];
                    }
                    tempBoard.board[i][0] = 0;
                }
            }
        }
        if(!isIdentical(nowBoard, tempBoard)) {
            twoZeroFourEight.push(tempBoard);
        }
        
        // 좌측으로
        memcpy(tempBoard.board, nowBoard.board, sizeof(nowBoard.board));
        for(int i=0;i<n;++i) {
            for(int j=0;j<n-1;++j) {
                if(tempBoard.board[i][j] != 0 && tempBoard.board[i][j] == tempBoard.board[i][j+1]) {
                    tempBoard.board[i][j] ++;
                    tempBoard.board[i][j+1] = 0;
                    findBlock[tempBoard.board[i][j]] = true;
                }
                if(tempBoard.board[i][j] == 0) {
                    for(int k=j+1;k<=n-1;++k) {
                        tempBoard.board[i][k - 1] = tempBoard.board[i][k];
                    }
                    tempBoard.board[i][n - 1] = 0;
                }
            }
        }
        if(!isIdentical(nowBoard, tempBoard)) {
            twoZeroFourEight.push(tempBoard);
        }
        
        // 위로
        memcpy(tempBoard.board, nowBoard.board, sizeof(nowBoard.board));
        for(int j=0;j<n;++j) {
            for(int i=0;i<n-1;++i) {
                if(tempBoard.board[i][j] != 0 && tempBoard.board[i][j] == tempBoard.board[i+1][j]) {
                    tempBoard.board[i][j] ++;
                    tempBoard.board[i+1][j] = 0;
                    findBlock[tempBoard.board[i][j]] = true;
                }
                if(tempBoard.board[i][j] == 0) {
                    for(int k=i+1;k<=n-1;++k) {
                        tempBoard.board[k - 1][j] = tempBoard.board[k][j];
                    }
                    tempBoard.board[n - 1][j] = 0;
                }  
            }
        }
        if(!isIdentical(nowBoard, tempBoard)) {
            twoZeroFourEight.push(tempBoard);
        }
        
        // 아래로
        memcpy(tempBoard.board, nowBoard.board, sizeof(nowBoard.board));
        for(int j=0;j<n;++j) {
            for(int i=n-1;i>=1;--i) {
                if(tempBoard.board[i][j] != 0 && tempBoard.board[i][j] == tempBoard.board[i-1][j]) {
                    tempBoard.board[i][j] ++;
                    tempBoard.board[i-1][j] = 0;
                    findBlock[tempBoard.board[i][j]] = true;
                }
                if(tempBoard.board[i][j] == 0) {
                    for(int k=i-1;k>=0;--k) {
                        tempBoard.board[k + 1][j] = tempBoard.board[k][j];
                    }
                    tempBoard.board[0][j] = 0;
                }
            }
        }
        if(!isIdentical(nowBoard, tempBoard)) {
            twoZeroFourEight.push(tempBoard);
        }
        
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
            if(temp != 0){
                temp = int(log2(double(temp)));
            }
            initBoard.board[i][j] = temp;
            findBlock[temp] = true;
        }
    }

    initBoard.convergeCount = 0;
    play2048();
    return 0;
}