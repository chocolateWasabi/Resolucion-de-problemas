#include <iostream>
#include <utility>
using namespace std;

int t, n, m;
int a[1001][2], b[1001][2];

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> t >> n;
    for(int i=1;i<=n;++i) {
        cin >> a[i][0];
        a[i][1] = a[i-1][1] + a[i][0];
    }
    cin >> m;
    for(int i=1;i<=m;++i) {
        cin >> b[i][0];
        b[i][1] = b[i-1][1] + b[i][0];
    }

    pair<int, int> _a, _b;
    _a.first = 0, _a.second = 1;
    int rem, count = 0;
    int temp_a, temp_b;
    for(;_a.first <= n && _a.second <= n;) {
        temp_a = a[_a.second][1] - a[_a.first][1];
        if(temp_a >= t) {
            ++ _a.first;
            _a.second = _a.first + 1;
            if(_a.first == 3) {
                int test = 3;
            }
        } else {
            rem = t - (temp_a);
            _b.first = 0, _b.second = 1;

            for(;_b.first < m && _b.second <= m;) {
                temp_b = b[_b.second][1] - b[_b.first][1];
                if(temp_b == rem) {
                    ++ count;
                    cout << _a.first + 1 << "~" << _a.second << ' ' << _b.first + 1 << "~" << _b.second << '\n';
                    ++ _b.first;
                } else if(temp_b > rem) {
                    ++ _b.first;
                } else {
                    ++ _b.second;
                }
            }
            
            // 어느 조건에 _a의 포인터를 바꾸어야 하나?
            // 그냥 증가시키면 건너 뛰는 케이스들이 생김
            ++ _a.second;
        }
    }

    cout << count;
    return 0;
}