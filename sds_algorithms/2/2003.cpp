#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n][2];
    memset(a, 0, sizeof(a));
    for(int i=1;i<=n;++i) {
        cin >> a[i][0];
        if(i) {
            a[i][1] = a[i-1][1] + a[i][0];
        } else {
            a[i][1] = 0;
        }
    }

    int count = 0;
    // count가 int여도 되네? - 이거 계산 어떻게 하지...
    for(int i=0, j=1;i<n && j<=n;) {
        if(a[j][1] - a[i][1] == m) {
            ++ count;
            ++ j;
        } else if(a[j][1] - a[i][1] < m) {
            ++ j;
        } else {
            ++ i;
        }
    }

    cout << count;
    return 0;
}