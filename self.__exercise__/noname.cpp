#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        cout << '#' << t << ' ' << t * 3 << '\n';
    }
    
    return 0;
}