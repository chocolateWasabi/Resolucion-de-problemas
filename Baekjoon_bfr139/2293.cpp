// BOJ 2293 동전 1 (DP, Knapsack)
#include <iostream>
#include <set>
using namespace std;

set <int> value;
int cases[2][10010]; // by switching

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=0, tmp;i<n;++i){
        cin >> tmp;
        value.insert(tmp);
    }
    
    int flag = 0;
    for(auto i:value){
        if(i > k) break;
        flag ^= 1;
        for(int j=1;j<i;++j){
            cases[flag][j] = cases[flag^1][j];
        }
        cases[flag][i] = cases[flag^1][i] + 1;
        for(int j=i+1;j<=k;++j){
            cases[flag][j] = cases[flag^1][j] + cases[flag][j-i];
        }
    } // 모든 상태 전부를 가질 필요 없고, 현재랑 그 이전의 경우만 가지고 있으면 된다.

    cout << cases[flag][k];
    return 0;
}