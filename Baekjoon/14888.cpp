#include <iostream>
using namespace std;

long long nums[12];
int n, add, sub, mul, quo;

void oper(int num, int current_val, long long& min, long long& max){
    if(num == n){
        min = current_val < min? current_val: min;
        max = current_val > max? current_val: max;
        return;
    }
    if(add > 0){
        add --;
        oper(num + 1, current_val + nums[num], min, max);
        add ++;
    }
    if(sub > 0){
        sub --;
        oper(num + 1, current_val - nums[num], min, max);
        sub ++;
    }
    if(mul > 0){
        mul --;
        oper(num + 1, current_val * nums[num], min, max);
        mul ++;
    }
    if(quo > 0){
        quo --;
        oper(num + 1, current_val / nums[num], min, max);
        quo ++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;++i){
        cin >> nums[i];
    }
    cin >> add >> sub >> mul >> quo;

    long long min, max;
    min = 99999999999;
    max = -99999999999;
    oper(1, nums[0], min, max);

    cout << max << endl << min;

    return 0;
}