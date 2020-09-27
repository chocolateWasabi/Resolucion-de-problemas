// 구슬 탈출 2 (삼성 기출)
#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

typedef class {
public:
    pair<int, int> red, blue;
    int leanCount;
} bead;

int n, m;
char board[11][11];
pair<int, int> goal;
bead initState;
queue<bead> beadState;
int visited[11][11][11][11];

const int dx[] = {0, 0, -1, +1};
const int dy[] = {-1, +1, 0, 0};

inline bool inRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m? true: false;
}

inline void leanProcess(int dir, pair<int, int>& nowState, pair<int, int>& newState, char beadColor, int& findGoal) {
    bool isFindGoal = false;
    if(dir == 0 || dir == 1) {
        int j;
        for(j = nowState.second;;j = j + dy[dir]) {
            if(inRange(nowState.first, j + dy[dir])) {
                if(nowState.first == goal.first && j + dy[dir] == goal.second) {
                    // Goal 진입
                    isFindGoal = true;
                    j = j + dy[dir];

                    break;
                }
                if(board[nowState.first][j + dy[dir]] != '.') {
                    break;
                }
            }
            else {
                break;
            }
        }
        newState.first = nowState.first;
        newState.second = j;
    }
    else if(dir == 2 || dir == 3) {
        int i;
        for(i = nowState.first;;i = i + dx[dir]){
            if(inRange(i + dx[dir], nowState.second)) {
                if(i + dx[dir] == goal.first && nowState.second == goal.second) {
                    // Goal 진입
                    isFindGoal = true;
                    i = i + dx[dir];

                    break;
                }
                if(board[i + dx[dir]][nowState.second] != '.') {
                    break;
                }
            }
            else {
                break;
            }
        }
        newState.first = i;
        newState.second = nowState.second;
    }

    board[nowState.first][nowState.second] = '.';
    if(!isFindGoal) {
        board[newState.first][newState.second] = beadColor;
    }
    else {
        // Goal 찾은 경우 (newState == goal)
        if(beadColor == 'R') {
            findGoal = findGoal | 1;
        }
        else if(beadColor == 'B') {
            findGoal = findGoal | 2;
        }
    }
}

void printBoard(int leanCount) {
    cout << "leanCount: " << leanCount << '\n';
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout << board[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}

void beadEscape() {
    int minLean = 11;
    beadState.push(initState);
    visited[initState.red.first][initState.red.second][initState.blue.first][initState.blue.second] = 1;
    bead nowState, prevState;
    int type;

    prevState.red.first = prevState.red.second = prevState.blue.first = prevState.blue.second = 10;
    while(!beadState.empty()) {
        nowState = beadState.front();
        beadState.pop();

        if(nowState.leanCount >= 10) {
            continue;
        }

        board[prevState.red.first][prevState.red.second] = board[prevState.blue.first][prevState.blue.second] = '.';
        board[nowState.red.first][nowState.red.second] = 'R';
        board[nowState.blue.first][nowState.blue.second] = 'B';

        //printBoard(nowState.leanCount);

        if(nowState.red.first == nowState.blue.first) { // 같은 행에 있는 경우
            if(nowState.red.second < nowState.blue.second) { // 우측 기울임 시 blue부터, 좌측(-) 기울임 시 red부터 
                type = 1;
            }
            else { // 우측 기울임 시 red부터, 좌측 기울임 시 blue부터
                type = 2;
            }
        }
        else {
            if(nowState.red.second == nowState.blue.second) { // 같은 열에 있는 경우
                if(nowState.red.first < nowState.blue.first) { // 위로(-) 기울임 시 red부터, 아래로 기울임 시 blue부터
                    type = 3;
                }
                else { // 위로 기울임 시 blue부터, 아래로 기울임 시 red부터
                    type = 4;
                }
            }
            else { // 아예 다른 곳에 있는 경우
                type = 5;
            }
        }

        // 새로 queue에 넣는 과정
        bead newState;
        int findGoal;
        for(int i=0;i<4;++i) {
            findGoal = 0;
            if(i + 1 == type) {
                leanProcess(i, nowState.red, newState.red, 'R', findGoal);
                leanProcess(i, nowState.blue, newState.blue, 'B', findGoal);
            }
            else {
                leanProcess(i, nowState.blue, newState.blue, 'B', findGoal);
                leanProcess(i, nowState.red, newState.red, 'R', findGoal);
            }

            
            // 원 상태로 복귀
            board[newState.red.first][newState.red.second] = '.';
            board[nowState.red.first][nowState.red.second] = 'R';
            board[newState.blue.first][newState.blue.second] = '.';
            board[nowState.blue.first][nowState.blue.second] = 'B';

            if(!findGoal) {
                // push
                if(!visited[newState.red.first][newState.red.second][newState.blue.first][newState.blue.second]){
                    newState.leanCount = nowState.leanCount + 1;
                    beadState.push(newState);
                    visited[newState.red.first][newState.red.second][newState.blue.first][newState.blue.second] = 1;
                }
            }
            else {
                // 구슬 하나라도 hole에 빠진 경우
                if((findGoal & 1) && !(findGoal & 2)) { // 성공 케이스
                    minLean = nowState.leanCount + 1 < minLean? nowState.leanCount + 1: minLean;
                }
                else { // 실패 케이스 - 소각 (do nothing)
                }

                // 원 상태로 복귀
                board[goal.first][goal.second] = 'O';
            }
        }

        prevState = nowState;
    }

    if(minLean == 11) {
        cout << -1;
    }
    else {
        cout << minLean;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0;i<n;++i) {
        cin >> board[i];
        for(int j=0;j<m;++j) {
            switch(board[i][j]) {
                case 'R': initState.red.first=i; initState.red.second=j; break;
                case 'B': initState.blue.first=i; initState.blue.second=j; break;
                case 'O': goal.first=i;goal.second=j; break;
                default: break;
            }
        }
    }

    initState.leanCount = 0;
    beadEscape();
    return 0;
}