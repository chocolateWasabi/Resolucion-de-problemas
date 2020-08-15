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

int main() {
    int n, m;
    int T;
    cin >> T;
    for(int t=1;t<=T;++t) {
        cin >> n >> m;
        cout << getCombination(m, n) << '\n';
    }
    return 0;
}