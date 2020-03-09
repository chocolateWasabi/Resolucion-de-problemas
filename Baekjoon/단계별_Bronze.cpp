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
}