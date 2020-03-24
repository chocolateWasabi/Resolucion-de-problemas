// 그래프 - 보급로
#include <iostream>
#include <cstring>
using namespace std;

int min(int a, int b){
    return a < b? a: b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int n, check[110][110];
    char mapd[110][110];
    for(int t=1;t<=T;++t){
        memset(check, 0, sizeof(check));
        cin >> n;
        for(int i=0;i<n;++i){
            cin >> mapd[i];
            for(int j=0;j<n;++j){
                if(i>0 && j>0){
                    check[i][j] = min(check[i-1][j], check[i][j-1]) + int(mapd[i][j]-'0');
                }
                else if(i==0 && j>0){
                    check[i][j] = check[i][j-1] + int(mapd[i][j]-'0');
                }
                else if(i>0 && j==0){
                    check[i][j] = check[i-1][j] + int(mapd[i][j]-'0');
                }
                else {
                    check[i][j] = int(mapd[i][j]-'0');
                }
            }
        }
        cout << '#' << t << ' ' << check[n-1][n-1] << '\n';
    }

    return 0;
}