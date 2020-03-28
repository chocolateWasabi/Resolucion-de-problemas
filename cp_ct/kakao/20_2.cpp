#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int check[100001];

vector<int> solution(string s) {
    vector<int> answer;
    memset(check, 0, sizeof(check));

    int n = 0; // 튜플 원소의 수
    int make_num = 0; // 숫자 만들기
    int count; // 각 subset 별 원소의 수
    int par_start = 0; // 처리할 괄호 구분
    for(auto i:s){
        if(i == '{'){
            count = 0;
            par_start ++;
        }
        else if(i == '}'){
            if(par_start == 2){
                check[make_num] ++;
                make_num = 0;
                count ++;
                n = count > n? count: n;
            }
            par_start --;
        }
        else if(i == ','){
            check[make_num] ++;
            count ++;
            make_num = 0;
        }
        else { // number
            make_num *= 10;
            make_num += int (i - '0');
        }
    }

    answer.clear();
    for(int i=0;i<n;++i){
        answer.push_back(0);
    }

    for(int i=1;i<=100000;++i){
        if(check[i]){
            answer[n-check[i]] = i;
        }
    }

    return answer;
}

int main(){
    string s;
    cin >> s;
    vector<int> res;
    res = solution(s);

    for(auto i:res){
        cout << i << ' ';
    }
    return 0;
}