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
/*
// BOJ ID 9251 (review)
#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b){
    return a > b? a: b;
}

int main(){
    char dat[2][1001];
    cin >> dat[0] >> dat[1];
    int len[2];
    len[0] = strlen(dat[0]), len[1] = strlen(dat[1]);
    int crit = len[0] <= len[1]? 0: 1;
    int check[2][1001];
    memset(check, 0, sizeof(check));
    int current_max, flag = 0;
    for(int i=0;i<len[crit];++i){
        current_max = 0;
        flag ^= 1;
        for(int j=0;j<len[crit^1];++j){
            if(dat[crit^1][j] == dat[crit][i]){
                check[flag][j] = max(check[flag^1][j], current_max + 1);
            }
            else{
                check[flag][j] = check[flag^1][j];
            }
            current_max = check[flag^1][j] > current_max? check[flag^1][j]: current_max;
        }
    }
    current_max = 0;
    for(int i=0;i<len[crit^1];++i){
        current_max = check[flag][i] > current_max? check[flag][i]: current_max;
    }
    cout << current_max;
    return 0;
}*/