#include <iostream>
#include <cstring>
#include <set>
#include <string>
using namespace std;

const int an = int('z' - 'a' + 1);
int alpha[an][400];
int order;
char my_string[401];
bool flag;
multiset<string> candidate;
char current[401];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        memset(alpha, 0, sizeof(alpha));
        memset(my_string, 0, sizeof(my_string));
        memset(current, 0, sizeof(current));
        candidate.clear();

        cin >> order;
        cin >> my_string;

        int my_len = strlen(my_string);
        for(int i=0;i<my_len;++i){
            ++ alpha[int(my_string[i]-'a')][0];
            alpha[int(my_string[i]-'a')][alpha[int(my_string[i]-'a')][0]] = i;
        }

        cout << '#' << t << ' ';
        
        flag = false;
        for(int i=0, cnt=0;i<an && !flag;++i){
            for(int j=1;j<=alpha[i][0];++j){
                ++ cnt;
                //-- alpha[i][0];
                if(cnt == order){
                    flag = true;

                    // 여기서 후보 값들 중 재 정렬해서 찾기
                    for(int k=1;k<=alpha[i][0];++k){
                        strcpy(current, &my_string[alpha[i][k]]);
                        candidate.insert(current);
                    }

                    int new_count = 0;
                    for(auto u:candidate){
                        ++ new_count;
                        if(new_count == j){
                            cout << u;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if(!flag){
            cout << "none";
        }
        cout << '\n';
    }
    return 0;
}