#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    
    int n, m;
    int tile[55][55];
    for(int t=1;t<=T;++t){
        cin >> n >> m;
        memset(tile, 0, sizeof(tile));
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                cin >> tile[i][j];
            }
        }

        for(int i=n;i>1;--i){
            for(int j=m;j>1;--j){
                if(tile[i][j] && tile[i-1][j] && tile[i][j-1] && tile[i-1][j-1]){
                    tile[i][j] = tile[i-1][j] = tile[i][j-1] = tile[i-1][j-1] = 2;
                }
            }
        } // 거꾸로 보면서 가능한 경우 다 2로 채우고 (0만 아니면 채울 수 있음)

        bool if_valid = true;
        for(int i=1;i<=n && if_valid;++i){
            for(int j=1;j<=m;++j){
                if(tile[i][j] == 1){
                    // 만약 1을 만난다면 못 채웠단 말이므로 NO 출력
                    if_valid = false;
                    break;
                }
            }
        }

        if(if_valid){
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}