#include <iostream>
using namespace std;

#define maxima 100001

long long n, s;
long long series[maxima][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;

    for(int i=1;i<=n;++i) {
        cin >> series[i][0];
        series[i][1] = series[i-1][1] + series[i][0];
    }

    int left, right;
    int min_length = maxima;
    for(left=0, right=1;left <= right && right <= n;) {
        if(series[right][1] - series[left][1] == s) {
            min_length = right - left < min_length? right - left: min_length;
            ++ left;
        } else if(series[right][1] - series[left][1] < s) {
            ++ right;
        } else {
            ++ left;
        }
    }

    cout << (min_length != maxima? min_length: 0);
    return 0;
}