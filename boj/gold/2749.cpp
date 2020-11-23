// BOJ 2749
// calculate fibonacci using matrix calculation.
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    const unsigned long long divisor = 1000000;

    // matrix initialize
    unsigned long long mat_fibo[64][2][2];
    mat_fibo[0][0][0] = 1;
    mat_fibo[0][0][1] = 1;
    mat_fibo[0][1][0] = 1;
    mat_fibo[0][1][1] = 0;

    // pre-processing fibonacci matrix
    for(int i=1;i<63;++i) {
        mat_fibo[i][0][0] = (mat_fibo[i-1][0][0] * mat_fibo[i-1][0][0] + mat_fibo[i-1][0][1] * mat_fibo[i-1][1][0]) % divisor;
        mat_fibo[i][0][1] = (mat_fibo[i-1][0][0] * mat_fibo[i-1][0][1] + mat_fibo[i-1][0][1] * mat_fibo[i-1][1][1]) % divisor;
        mat_fibo[i][1][0] = (mat_fibo[i-1][1][0] * mat_fibo[i-1][0][0] + mat_fibo[i-1][1][1] * mat_fibo[i-1][1][0]) % divisor;
        mat_fibo[i][1][1] = (mat_fibo[i-1][1][0] * mat_fibo[i-1][0][1] + mat_fibo[i-1][1][1] * mat_fibo[i-1][1][1]) % divisor;
    }

    // calculate multiplier matrix
    unsigned long long mul_mat_fibo[2][2] = {{1, 0}, {0, 1}};

    unsigned long long n;
    int i = 0;
    cin >> n;

    if(!n) {
        cout << 0;
        return 0;
    }

    n--;
    while(n > 0) {
        if(n & 1) {
            unsigned long long _mul_mat_fibo[2][2];
            _mul_mat_fibo[0][0] = (mat_fibo[i][0][0] * mul_mat_fibo[0][0] + mat_fibo[i][0][1] * mul_mat_fibo[1][0]) % divisor;
            _mul_mat_fibo[0][1] = (mat_fibo[i][0][0] * mul_mat_fibo[0][1] + mat_fibo[i][0][1] * mul_mat_fibo[1][1]) % divisor;
            _mul_mat_fibo[1][0] = (mat_fibo[i][1][0] * mul_mat_fibo[0][0] + mat_fibo[i][1][1] * mul_mat_fibo[1][0]) % divisor;
            _mul_mat_fibo[1][1] = (mat_fibo[i][1][0] * mul_mat_fibo[0][1] + mat_fibo[i][1][1] * mul_mat_fibo[1][1]) % divisor;

            memcpy(mul_mat_fibo, _mul_mat_fibo, sizeof(mul_mat_fibo));
        }
        n >>= 1;
        i++;
    }

    cout << mul_mat_fibo[0][0];
    return 0;
}