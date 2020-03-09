/*
// BOJ ID 12865
#include <iostream>
#include <cstring>
#define max_weight 100010
using namespace std;

int n, k;
int weight_value_info[2][max_weight];

int min(int a, int b){
    return a > b? a: b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(weight_value_info, 0, sizeof(weight_value_info));

    int n, k;
    cin >> n >> k;
    int flag = 0;
    for(int i=1;i<=n;++i){
        int w, v;
        cin >> w >> v;
        flag ^= 1;
        for(int j=1;j<w;++j){
            weight_value_info[flag][j] = weight_value_info[flag^1][j];
        }
        for(int j=w;j<=k;++j){
            weight_value_info[flag][j] = max(weight_value_info[flag^1][j], weight_value_info[flag^1][j-w]+v);
        }/*
        for(int j=1;j<=k;++j){
            cout << weight_value_info[flag][j] << ' ';
        }
        cout << endl;
    }
    cout << weight_value_info[flag][k];
    return 0;
}
*/