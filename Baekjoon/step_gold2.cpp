// BOJ ID 1976
#include <iostream>
using namespace std;

int city[201];

int getHead(int idx) {
    if(idx == city[idx]) {
        return idx;
    }
    return getHead(city[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;++i) {
        city[i] = i;
    }
    int conn;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j) {
            cin >> conn;
            if(j > i) {
                if(conn) {
                    city[getHead(j)] = getHead(i);
                }
            }
        }
    }
    for(int i=1;i<=n;++i) {
        city[i] = getHead(i);
    }
    int prev, now;
    cin >> prev;
    bool failure = false;
    for(int i=1;i<m;++i) {
        cin >> now;
        if(!failure) {
            if(getHead(prev) != getHead(now)) {
                failure = true;
            }
            prev = now;
        }
    }
    if(failure) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    return 0;
}