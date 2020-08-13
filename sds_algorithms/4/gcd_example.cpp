#include <iostream>
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

int main(){
    cout << gcd(36, 132);
    return 0;
}