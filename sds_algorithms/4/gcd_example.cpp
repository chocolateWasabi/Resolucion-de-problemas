#include <iostream>
#include <tuple>
using namespace std;

int gcd_recursion(int a, int b) {
    if(!b) {
        return a;
    }
    return gcd_recursion(b, a % b);
}

int gcd(int a, int b) {
    while(b) {
        // 자동으로 뒤바뀜 (a<b인 경우)
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
    // 문제에 따라 절대값이 붙을 수도 있고 아닐 수도 있음
    // return abs(a);
}

tuple<int, int, int> extended_gcd(int a, int b) {
    if(!b) {
        return make_tuple(a, 1, 0);
    }
    int g, x, y;
    tie(g, x, y) = extended_gcd(b, a % b);
    cout << g << ' ' << y << ' ' << x-(a/b)*y << '\n';
    return make_tuple(g, y, x-(a/b)*y);
}

tuple<int, int, int> extended_gcd2(int a, int b) {
    int idx = 0;
    int s[2] = {1, 0};
    int t[2] = {0, 1};
    int r[2] = {a, b};

    while(r[idx^1]) {
        cout << s[idx] << ' ' << t[idx] << ' ' << r[idx] << '\n';
        s[idx] -= s[idx^1] * (r[idx] / r[idx^1]);
        t[idx] -= t[idx^1] * (r[idx] / r[idx^1]);
        r[idx] %= r[idx^1];
        idx ^= 1;
    }
    return make_tuple(r[idx], s[idx], t[idx]);
}

int main(){
    int g, x, y;
    tie(g, x, y) = extended_gcd(71, 240);
    cout << g << ' ' << x << ' ' << y;
    return 0;
}