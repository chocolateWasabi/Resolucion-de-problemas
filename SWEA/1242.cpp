#include <iostream>
#include <cstring>
#include <cmath>
//#include <fstream>
using namespace std;
 
// 메모리 문제로 전역 변수로 설정
char dat[2010][510];
int n, m;
int x, y;
 
int ch2i(char c){
    if(c >= '0' && c <= '9')
        return c-'0';
    else if(c >= 'A' && c <= 'F')
        return c-'A'+10;
    return -1;
}
 
int getbin(int hex, int d){
    int t=int(pow(2.0, double(d-1)));
    return (hex & t) == t? 1: 0;
}
 
bool validity_check(int crypto_code[]){
    if(((crypto_code[0]+crypto_code[2]+crypto_code[4]+crypto_code[6])*3+(crypto_code[1]+crypto_code[3]+crypto_code[5])+crypto_code[7])%10 == 0)
        return true;
    return false;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream fin;
    //fin.open("C:\\Users\\yoseo\\Desktop\\PSE\\June_2w\\sample_input.txt");
    int T;
    if(/*fin.is_open()*/true){
        cin >> T;
         
        int ch2i_n;
        int checkitout[4], cmp, cio;
        int crypto_code[8], digit;
        int mag = 1, amount;
        int sum;
        int pass;
        for(int t=1;t<=T;++t){
            sum = 0;
            cin >> n >> m;
            memset(dat, 0, sizeof(dat));
            for(int i=0;i<n;++i)
                cin >> dat[i];
             
            // searching
            for(int i=n-1;i>=0;--i){
                for(int j=m-1;j>=0;--j){
                    if(dat[i][j]!='0'){
                        memset(crypto_code, 0, sizeof(crypto_code));
                        int k;
                        amount = 0;
                        for(digit=7;digit>=0;--digit){
                            memset(checkitout, 0, sizeof(checkitout));
                            cmp = 1;
                            cio = 3;
                            if(digit==7){
                                x = i, y = j;
                                ch2i_n = ch2i(dat[x][y]);
                                for(k=1;k<=4;++k){
                                    if(getbin(ch2i_n, k) == 0) continue;
                                    else break;
                                }
                                pass = k - 1;
                            }
                            //cout << k << endl;
                            bool firstflag = true; // 이전에 사용하던 값 그대로 사용
                            //return 0;
                            for(;amount<mag*56;--y){
                                ch2i_n = ch2i(dat[x][y]);
                                for(k=firstflag?k:1;k<=4 && amount<mag*56;++k){
                                    if(getbin(ch2i_n, k) == cmp){
                                        checkitout[cio] ++;
                                        amount ++;
                                    }
                                    else{
                                        cmp = cmp ^ 1;
                                        cio --;
                                        if(cio<0) break;
                                        checkitout[cio] ++;
                                        amount ++;
                                    }
                                }
                                if(cio<0) break;
                                firstflag = false;
                            }
                            // 여기서 배율 체크  mag
                            if(digit==7){
                                mag=1;
                                for(int max=1;max<36;++max){
                                    if(checkitout[0]%max==0 && checkitout[1]%max==0 && checkitout[2]%max==0 && checkitout[3]%max==0){
                                        mag = max;
                                    }
                                }
                                //cout << mag << '.';
                                //cout << '.';
                            }
                            // 1배율만 
 
                            for(int qwer=0;qwer<4;++qwer){
                                checkitout[qwer] /= mag;
                                //cout << checkitout[qwer];
                            }
                            int ratio = checkitout[0]*1000+checkitout[1]*100+checkitout[2]*10+checkitout[3];
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
                        /*for(int a=0;a<8;++a){
                            cout << crypto_code[a];
                        }
                        cout << '.';*/
                        if(validity_check(crypto_code)){
                            for(int a=0;a<8;++a){
                                sum += crypto_code[a];
                            }
                        }
 
                        // 제거
                        int del_pos;
                        char del_std;
                        del_std = dat[i][j];
                        for(del_pos=i;;--del_pos){
                            if(del_pos<0 || dat[del_pos][j] != del_std)
                                break;
                        }
                         
                        for(int b=i;b>del_pos;--b){
                            for(int b2=j;b2>j-mag*14;--b2){
                                dat[b][b2] = '0';
                            }
                            int tmp2 = 16 - int(pow(2.0, double(pass)));
                            //cout << tmp2 << endl;
                            int tmp3 = (ch2i(dat[b][j-mag*14]) & tmp2);
                            if(tmp3 >= 0 && tmp3 <= 9)
                                dat[b][j-mag*14] = tmp3 + '0';
                            else if(tmp3 >= 10 && tmp3 <= 15)
                                dat[b][j-mag*14] = tmp3 + 'A' - 10;
                            else {//error
                            }
                        }
    /*
                        for(int q=0;q<n;++q){
                            cout << dat[q] << '\n';
                        }
                         
                        return 0;*/
                    }
                }
            }
            cout << '#' << t << ' ' << sum << '\n';
        }
    }
    else cout << "open error";
    return 0;
}