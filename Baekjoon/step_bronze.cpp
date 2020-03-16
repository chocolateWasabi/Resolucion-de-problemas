/*
// BOJ ID 5543
#include <iostream>
using namespace std;

int main(){
    int min, tmp, tmp2;
    cin >> min;
    cin >> tmp;
    min = tmp < min ? tmp: min;
    cin >> tmp;
    min = tmp < min ? tmp: min;
    cin >> tmp >> tmp2;
    min += tmp < tmp2 ? tmp: tmp2;
    cout << min - 50;
    return 0;
}*/

/*
// BOJ ID 10996
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i=1;i<=2*n;++i){
        for(int j=1;j<=n;++j){
            if((i&1) && (j&1) || !(i&1) && !(j&1)){
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}

*/

// BOJ ID 14681
#include <iostream>
using namespace std;

int main(){
    int x, y;

    cin >> x >> y;
    if(x > 0){
        if(y > 0){
            cout << '1';
        }
        else {
            cout << '4';
        }
    }
    else {
        if(y > 0){
            cout << '2';
        }
        else {
            cout << '3';
        }
    }
    return 0;
}