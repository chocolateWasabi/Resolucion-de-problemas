// 최대 상금 문제
#include <iostream>
#include <cstring>
using namespace std;

char digit[7];
int n;
int check[6][6];
int len;
char maxdigit[7];
int so_far;

void checklarger(){
    memset(check, 0, sizeof(check));
    char local_max;
    for(int i=0;i<len;++i){
        local_max = digit[i];
        for(int j=i+1;j<len;++j){
            if(digit[j]>local_max){
                local_max = digit[j];
            }
        }
        if(local_max != digit[i]){
            for(int j=i+1;j<len;++j){
                if(digit[j] == local_max){
                    check[i][0] ++;
                    check[i][check[i][0]] = j;
                }
            }
        }
    }
}

void swap(char &a, char &b){
    char tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void getmax(int level, int var){
    if(var == n || level == len){
        bool flag = true;
        for(int i=0;i<len;++i){
            if(digit[i]>maxdigit[i]){
                flag = true;
                break;
            }
            else if(digit[i]<maxdigit[i]){
                flag = false;
                break;
            }
        }
        if(flag){
            if(!strncmp(maxdigit, digit, sizeof(digit))){            
                so_far = var < so_far? var: so_far;
            }
            else{
                so_far = var;
                memcpy(maxdigit, digit, sizeof(digit));
            }
            //so_far = var > so_far? var: so_far;
        }
        return;
    }

    int check_backup[6][6];
    if(check[level][0] != 0){
        for(int i=check[level][0];i>0;--i){

            // 백업
            int tmp_pos = check[level][i];
            memcpy(check_backup, check, sizeof(check));
            
            // 변화
            swap(digit[level], digit[check[level][i]]);
            checklarger();
            
            // 진입
            getmax(level + 1, var + 1);

            // 복구
            memcpy(check, check_backup, sizeof(check));
            swap(digit[level], digit[tmp_pos]);
        }
    }
    else {
        getmax(level + 1, var);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        cin >> digit >> n;
        len = strlen(digit);
        memcpy(maxdigit, digit, sizeof(digit));
        checklarger();
        so_far = 0;
        getmax(0, 0);
        so_far = n - so_far;
        if(so_far & 1){
            bool flag = false;
            for(int i=0;i<len && !flag;++i){
                for(int j=i+1;j<len;++j){
                    if(maxdigit[i]==maxdigit[j]){
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag){
                swap(maxdigit[len-1], maxdigit[len-2]);
            }
        }
        cout << '#' << t << ' ' << maxdigit << '\n';
        //cout << so_far << '\n';
    }
    return 0;
}