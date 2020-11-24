// 2740
#include <iostream>
using namespace std;

int n, m, k;
int a[100][100], b[100][100], c[100][100];

int main() {
    cin >> n >> m;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            cin >> a[i][j];
        }
    }
    cin >> m >> k;
    for(int i=0;i<m;++i) {
        for(int j=0;j<k;++j) {
            cin >> b[i][j];
        }
    }

    for(int i=0;i<n;++i) {
        for(int j=0;j<k;++j) {
            for(int q=0;q<m;++q) {
                c[i][j] += (a[i][q] * b[q][j]);
            }
            cout << c[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}