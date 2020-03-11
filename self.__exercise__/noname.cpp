#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int in, pos1;
    for(int i=1;i<=n;++i){
        cin >> in;
        if(in == 1){
            pos1 = i;
        }
    }

    int ws, wt;
    int min_val = 999999;
    int now;
    for(ws=pos1-k+1;ws<=pos1;++ws){
        wt=ws+k-1;

        now = 1 + ceil(double(ws-1)/(k-1)) + ceil(double(n-wt)/(k-1));
        min_val = now < min_val? now: min_val;
    }

    cout << min_val;
    return 0;
}