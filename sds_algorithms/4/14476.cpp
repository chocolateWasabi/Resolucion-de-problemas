#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b) {
    while(b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int n;
int dat[1000000][3];
// 0: original data
// 1: gcd left to right
// 2: gcd right to left

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(dat, 0, sizeof(dat));
    for(int i=0, t;i<n;++i) {
        cin >> t;
        dat[i][0] = t;
        dat[i][1] = gcd(dat[i][0], !i? dat[i][0]: dat[i-1][1]);
    }
    dat[n-1][2] = dat[n-1][0];
    for(int i=n-2;i>=0;--i) {
        dat[i][2] = gcd(dat[i][0], dat[i+1][2]);
    }

    int maximum, omit;
    maximum = 0, omit = -1;

    for(int i=0;i<n;++i) {
        int newGcd;
        if(i == 0) {
            newGcd = dat[i+1][2];
        } else if(i == n-1) {
            newGcd = dat[i-1][1];
        } else {
            newGcd = gcd(dat[i-1][1], dat[i+1][2]);
        }
        if(dat[i][0] % newGcd) {
            if(newGcd > maximum) {
                maximum = newGcd;
                omit = dat[i][0];
            }
        }
    }
    if(maximum) {
        cout << maximum << ' ' << omit;
    } else {
        cout << -1;
    }

    return 0;
}