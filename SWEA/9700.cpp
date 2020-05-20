#include <iostream>
using namespace std;

int main(){
    float p, q; // p: right side, q: put properly
    float s0, s1, s2;
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        cin >> p >> q;
        
        s1 = (1 - p) * q;
        s2 = p * (1 - q) * q;

        cout << '#' << t << ' ';
        if(s1 < s2){
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}