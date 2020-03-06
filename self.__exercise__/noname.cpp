#include <iostream>
#include <set>
using namespace std;

set <int> value;
int cases[110][10010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for(int i=0, tmp;i<n;++i){
        cin >> tmp;
        value.insert(tmp);
    }
    
    int i2=1;
    for(auto i:value){
        for(int j=1;j<i;++j){
            cases[i2][j] = cases[i2-1][j];
        }
        cases[i2][i] = cases[i2-1][i] + 1;
        for(int j=i+1;j<=k;++j){
            cases[i2][j] = cases[i2-1][j] + cases[i2][j-i];
        }
        i2 ++;
    }

    /*
    for(int i=1;i<=n;++i){
        for(int j=1;j<=k;++j){
            cout << cases[i][j] << ' ';
        }
        cout << '\n';
    } */

    cout << cases[n][k];
    return 0;
}