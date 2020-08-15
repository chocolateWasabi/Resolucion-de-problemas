// 사전 BOJ ID 1256
#include <iostream>
using namespace std;

int combinationData[110][110];
int getCombination(int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    }
    if(combinationData[n][r]) {
        return combinationData[n][r];
    }
    // memoization
    return combinationData[n][r] = getCombination(n-1, r-1) + \
    getCombination(n-1, r);
}

inline int my_min(int a, int b) {
    return a < b? a: b;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int _n, _r;
    _n = n + m;
    _r = my_min(n, m);



    return 0;
}