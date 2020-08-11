#include <iostream>
using namespace std;

const long maxima = 1234567890;

long long getRatio(long long x, long long y) {
    return (y * 100) / x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long x, y;
    cin >> x >> y;

    long long originRatio = getRatio(x, y);

    long long l_bound, r_bound;
    l_bound = 0, r_bound = maxima;

    long long mid, res, get;
    res = 0;
    for(;l_bound < r_bound;) {
        mid = (l_bound + r_bound) / 2;
        get = getRatio(x + mid, y + mid);
        if(get == originRatio) {
            l_bound = mid + 1;
        } else {
            res = mid;
            r_bound = mid;
        }
    }

    cout << (res? res: -1);
    return 0;
}