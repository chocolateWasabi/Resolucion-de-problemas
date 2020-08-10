// 너무 전형적인 A형 문제
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

queue<pair<int, int> > water;
queue<pair<pair<int, int>, int> > hedgehog; // 좌표, 몇 번째 턴
char forest[51][51];
int futureForest[51][51];
bool visit[51][51];
int r, c;

const int dx[] = {0, 0, +1, -1};
const int dy[] = {-1, +1, 0, 0};

inline bool inRange(pair<int, int> next) {
    if( next.first >= 0 && next.first < r
        && next.second >= 0 && next.second < c) {
            return true;
        }
    return false;
}

void getFutureForest() {
    pair<int, int> now;
    int next_x, next_y;
    while(!water.empty()) {
        now = water.front();
        water.pop();

        for(int dir=0;dir<4;++dir) {
            next_x = now.first + dx[dir];
            next_y = now.second + dy[dir];
            if(inRange({next_x, next_y}) && !futureForest[next_x][next_y]) {
                futureForest[next_x][next_y] = futureForest[now.first][now.second] + 1;
                water.push({next_x, next_y});
            }
        }
    }
/*
    for(int i=0;i<r;++i) {
        for(int j=0;j<c;++j) {
            cout << futureForest[i][j] << ' ';
        }
        cout << '\n';
    }*/
}

int findRoute() {
    // hedgehog move
    pair<int, int> now;
    int nowCount;
    int nextCount, next_x, next_y;

    int minCount = 11111;
    // 초기값 최초에 너무 작게 잡아서 WA 뜸
    while(!hedgehog.empty()) {
        now = hedgehog.front().first;
        nowCount = hedgehog.front().second;
        hedgehog.pop();
        //visit[now.first][now.second] = true;

        if(forest[now.first][now.second] == 'D') {
            minCount = nowCount < minCount? nowCount: minCount;
            continue;
        }

        nextCount = nowCount + 1;

        for(int dir=0;dir<4;++dir) {
            next_x = now.first + dx[dir];
            next_y = now.second + dy[dir];

            if( inRange({next_x, next_y}) && 
                !(futureForest[next_x][next_y] > 0 && 
                futureForest[next_x][next_y] <= nextCount) &&
                forest[next_x][next_y] != 'X' &&
                !visit[next_x][next_y]) {

                hedgehog.push({{next_x, next_y}, nextCount});
                visit[next_x][next_y] = true;
            }
        }
    }

    return minCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;
    memset(visit, 0, sizeof(visit));

    for(int i=0;i<r;++i) {
        cin >> forest[i];
        for(int j=0;j<c;++j) {
            if(forest[i][j] == '*') {
                futureForest[i][j] = 1;
                water.push({i, j});
            } else if(forest[i][j] == 'S') {
                hedgehog.push({{i, j}, 1});
                forest[i][j] = '.';
                visit[i][j] = true;
            } else if(forest[i][j] == 'D' || forest[i][j] == 'X') {
                futureForest[i][j] = -1;
            }
        }
    }

    // 먼저 물이 어떻게 움직이는지 계산
    getFutureForest();

    // 고슴도치 움직이기
    int res = findRoute();
    if(res != 11111) {
        cout << res - 1;
    } else {
        cout << "KAKTUS";
    }

    return 0;
}