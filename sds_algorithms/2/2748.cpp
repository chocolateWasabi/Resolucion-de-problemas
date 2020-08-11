#include <iostream>
#include <cmath>
using namespace std;

long long getFibonacciByGeneralTerm(long long n) {
    double sqrt5 = sqrt(5.0);

    return n != 2? (long long)(
        (1.0/sqrt5) * \
        (pow((1.0+sqrt5)/2, double(n)) - \
        pow((1.0-sqrt5)/2, double(n))
    )): 1;

    // 왜 오차가 날까 ...?
}

int main() {
    long long f[91];
    long long n;
    f[0] = 0; f[1] = 1;

    for(int i=2;i<=90;++i) {
        f[i] = f[i-1] + f[i-2];
        //cout << f[i] << ' ' << getFibonacciByGeneralTerm(i) << '\n';
        /*if(f[i] != getFibonacciByGeneralTerm(i)) {
            cout << i << ' ';
        }*/
    }

    cin >> n;
    cout << f[n];

    return 0;
}