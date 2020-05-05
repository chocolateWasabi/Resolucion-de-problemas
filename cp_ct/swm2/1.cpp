#include <iostream>
using namespace std;

inline int max(int a, int b){
    return a > b ? a: b;
}

int main(){
    int n;
    cin >> n;
    long long local_min, local_max, accumulation, candidate;
    local_min = local_max = accumulation;
    candidate = -9999999999999;
    for(int tmp;n>0;--n){
        cin >> tmp;
        accumulation += tmp;
        if(accumulation < local_min){ // local 최소값 들어오면 local 최대값 초기화, 후보 선택 보류.
            local_min = accumulation;
            local_max = local_min;
        }
        if(accumulation > local_max){ // local 최대값 들어오면 후보 선택.
            local_max = accumulation;
            candidate = max(local_max-local_min, candidate);
        }
        candidate = max(candidate, tmp); // 지금 것 하나만 가져가는 경우.
        //cout << "lmin: " << local_min << "lmax: " << local_max << "cand: " << candidate << endl;
    }
    cout << candidate;
    return 0;
}