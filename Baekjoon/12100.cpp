// 2048 게임 (삼성 기출)
#include <iostream>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

typedef char byte;

typedef class {
public:
    byte data;
    bool label;
} dataType;

typedef class {
public:
    dataType board[25][25];
    int convergeCount;
} gameBoard;

int n;
bool findBlock[21];
gameBoard initBoard;
queue<gameBoard> twoZeroFourEight;

void printBoard(gameBoard);

bool isIdentical(gameBoard& a, gameBoard& b) { // 최적화 하는 부분 (for Hard)
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
    //printBoard(b);

    for(int i=0;i<n;++i) {
        for(int j=0;j<n; ++j) {
            b.board[i][j].label = false;
        }
    }

    return false;
}

const int dx[] = {0, 0, -1, +1};
const int dy[] = {-1, +1, 0, 0};

void printBoard(gameBoard temp) {
    if(temp.convergeCount <= 3) {
        cout << '\n' << "convergeCount: " << temp.convergeCount << '\n';
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(temp.board[i][j].label){
                    cout << '\'';
                }
                cout << int(temp.board[i][j].data) << ' ';
            }
            cout << '\n';
        }
    }
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
                if(tempBoard.board[i][j].data == 0) { // 0이면 당겨오기 - 다시 작성함
                    int pos = j;
                    for(;pos >= 0 && tempBoard.board[i][pos].data == 0;--pos);
                    if(pos >= 0) {
                        for(int k=0;k<=pos;++k) {
                            tempBoard.board[i][j-k] = tempBoard.board[i][pos-k];
                            tempBoard.board[i][pos-k].data = 0;
                            tempBoard.board[i][pos-k].label = false;
                        }
                        j=n; continue;
                    }
                }
                if(tempBoard.board[i][j].data != 0 && tempBoard.board[i][j].data == tempBoard.board[i][j-1].data
                    && !(tempBoard.board[i][j].label || tempBoard.board[i][j-1].label)) {
                    tempBoard.board[i][j].data ++;
                    tempBoard.board[i][j].label = true;

                    tempBoard.board[i][j-1].data = 0;
                    tempBoard.board[i][j-1].label = false;
                    
                    findBlock[tempBoard.board[i][j].data] = true;
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
                if(tempBoard.board[i][j].data == 0) {
                    int pos = j;
                    for(;pos < n && tempBoard.board[i][pos].data == 0;++pos);

                    if(pos < n) {
                        for(int k=0;k<n-pos;++k) {
                            tempBoard.board[i][j+k] = tempBoard.board[i][pos+k];
                            tempBoard.board[i][pos+k].data = 0;
                            tempBoard.board[i][pos+k].label = false;
                        }
                        j=-1; continue;
                    }
                }
                if(tempBoard.board[i][j].data != 0 && tempBoard.board[i][j].data == tempBoard.board[i][j+1].data
                    && !(tempBoard.board[i][j].label || tempBoard.board[i][j+1].label)) {
                    tempBoard.board[i][j].data ++;
                    tempBoard.board[i][j].label = true;

                    tempBoard.board[i][j+1].data = 0;
                    tempBoard.board[i][j+1].label = false;
                    findBlock[tempBoard.board[i][j].data] = true;
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
                if(tempBoard.board[i][j].data == 0) {
                    int pos = i;
                    for(;pos < n && tempBoard.board[pos][j].data == 0;++pos);

                    if(pos < n) {
                        for(int k=0;k<n-pos;++k) {
                            tempBoard.board[i+k][j] = tempBoard.board[pos+k][j];
                            tempBoard.board[pos+k][j].data = 0;
                            tempBoard.board[pos+k][j].label = false;
                        }
                        i=-1; continue;
                    }
                }  
                if(tempBoard.board[i][j].data != 0 && tempBoard.board[i][j].data == tempBoard.board[i+1][j].data
                    && !(tempBoard.board[i][j].label || tempBoard.board[i+1][j].label)) {
                    tempBoard.board[i][j].data ++;
                    tempBoard.board[i][j].label = true;

                    tempBoard.board[i+1][j].data = 0;
                    tempBoard.board[i+1][j].label = false;
                    findBlock[tempBoard.board[i][j].data] = true;
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
                if(tempBoard.board[i][j].data == 0) {
                    int pos = i;
                    for(;pos >= 0 && tempBoard.board[pos][j].data == 0;--pos);

                    if(pos >= 0) {
                        for(int k=0;k<=pos;++k) {
                            tempBoard.board[i-k][j] = tempBoard.board[pos-k][j];
                            tempBoard.board[pos-k][j].data = 0;
                            tempBoard.board[pos-k][j].label = false;
                        }
                        i=n; continue;  
                    }
                }
                if(tempBoard.board[i][j].data != 0 && tempBoard.board[i][j].data == tempBoard.board[i-1][j].data
                    && !(tempBoard.board[i][j].label || tempBoard.board[i-1][j].label)) {
                    tempBoard.board[i][j].data ++;
                    tempBoard.board[i][j].label = true;

                    tempBoard.board[i-1][j].data = 0;
                    tempBoard.board[i-1][j].label = false;
                    findBlock[tempBoard.board[i][j].data] = true;
                }
            }
        }
        if(!isIdentical(nowBoard, tempBoard)) {
            twoZeroFourEight.push(tempBoard);
        }
        
        /*if(findBlock[5]){
            cout << nowBoard.convergeCount;
        }*/
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
            initBoard.board[i][j].data = temp;
            initBoard.board[i][j].label = false;
            findBlock[temp] = true;
        }
    }

    initBoard.convergeCount = 0;
    play2048();
    return 0;
}