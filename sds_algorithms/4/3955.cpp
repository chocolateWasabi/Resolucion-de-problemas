// 확장형 유클리드 호제법 사용하는 부정방정식 문제
#include <iostream>
using namespace std;

typedef class {
public:
    int s, t, r;
} eGCDtype;

eGCDtype extendedEuclid(int a, int b) {
    int s[2], t[2], r[2];   
    s[0] = t[1] = 1;
    s[1] = t[0] = 0;
    r[0] = a, r[1] = b;
    int q;

    int idx = 0;

    while(r[idx] && r[idx^1]) {
        q = r[idx] / r[idx^1];
        r[idx] = r[idx] % r[idx^1];
        s[idx] = s[idx] - s[idx^1] * q;
        t[idx] = t[idx] - t[idx^1] * q;
        idx = idx ^ 1;
    }

    eGCDtype result;
    result.s = s[idx];
    result.t = t[idx];
    result.r = r[idx];

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    int k, c;
    cin >> T;
    for(int t=1;t<=T;++t) {
        cin >> k >> c;
        eGCDtype result = extendedEuclid(-k, c);
        //if(result.r != )
        cout << result.s << ' ' << result.t << ' ' << result.r << '\n';
    }

    return 0;
}