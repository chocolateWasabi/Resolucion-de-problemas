#include <iostream>
#include <cstring>
#include <utility>
using namespace std;
 
class simple_crypto {
private:
    int now;
    int n, m;
    char dat[55][110];
    pair<int, int> start_pos;
    int crypto_code[8];
    void find_start_pos();
    void get_crypto_code();
    bool validity_check();
    void crypto_main(){
        memset(dat, 0, sizeof(dat));
        cin >> n >> m;
        for(int i=0;i<n;++i)
            cin >> dat[i];
        find_start_pos();
        if(start_pos.first == -1) {
            // error
        }
        get_crypto_code();
        bool check = validity_check();
         
        cout << '#' << now << ' ';
        if(check == true){
            int sum = 0;
            for(int i=0;i<8;++i)
                sum += crypto_code[i];
            cout << sum << '\n';
        }
        else cout << 0 << '\n';
    }
public:
    simple_crypto(int now){
        this->now = now;
        crypto_main();
    }
};
 
void simple_crypto::find_start_pos(){
    for(int i=n-1;i>=0;--i){
        for(int j=m-1;j>=0;--j){
            if(dat[i][j]=='1'){
                start_pos.first = i;
                start_pos.second = j;
                return;
            }
        }
    }
}
 
void simple_crypto::get_crypto_code(){
    int checkitout[4], c;
    char cmp;
    int ratio;
    for(int digit=7;digit>=0;--digit){
        memset(checkitout, 0, sizeof(checkitout));
        c = 3;
        cmp = '1';
        for(int tmp=0;tmp<7;++tmp){
            if(dat[start_pos.first][start_pos.second-tmp] == cmp){
                checkitout[c] ++;
            }
            else{
                c--;
                cmp = cmp == '0'? cmp + 1: cmp - 1;
                checkitout[c] ++;
            }
        }
        start_pos.second-=7;
        ratio = checkitout[0]*1000+checkitout[1]*100+checkitout[2]*10+checkitout[3];
        switch(ratio){
            case 3211: // 0
                crypto_code[digit] = 0;
            break;
            case 2221: // 1
                crypto_code[digit] = 1;
            break;
            case 2122: // 2
                crypto_code[digit] = 2;
            break;
            case 1411: // 3
                crypto_code[digit] = 3;
            break;
            case 1132: // 4
                crypto_code[digit] = 4;
            break;
            case 1231: // 5
                crypto_code[digit] = 5;
            break;
            case 1114: // 6
                crypto_code[digit] = 6;
            break;
            case 1312: // 7
                crypto_code[digit] = 7;
            break;
            case 1213: // 8
                crypto_code[digit] = 8;
            break;
            case 3112: // 9
                crypto_code[digit] = 9;
            break;
        }
    }
    //for(int i=0;i<8;++i){
    //    cout << crypto_code[i];
    //}
}
 
bool simple_crypto::validity_check(){
    if(((crypto_code[0]+crypto_code[2]+crypto_code[4]+crypto_code[6])*3+(crypto_code[1]+crypto_code[3]+crypto_code[5])+crypto_code[7])%10 == 0)
        return true;
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        simple_crypto sc(t);
    }
    return 0;
}