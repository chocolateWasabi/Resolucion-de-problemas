// BOJ 11047 동전 0
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;

    long long value[10];
    for(int i=0;i<n;++i){
        cin >> value[i];
    }
    
    int cnt = 0;
    for(int i=n-1;i>=0;--i){
        if(value[i] > k){
            continue;
        }
        cnt += k / value[i];
        k %= value[i];
    }

    cout << cnt;
    return 0;
}