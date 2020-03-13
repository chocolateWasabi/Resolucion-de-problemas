// BOJ ID 4949
// 단순한 괄호 체크 문제 같지만, 문자열 처리 문제였다....
// ★ 은 중요 내용, ☆ 는 실수로 빠뜨린 내용. ( 각 2 개씩 숙지 ! )
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    string dataset;
    stack<char> brackets;
    bool if_balanced;

    string trash; // 버퍼 비워 주기 위한 임시 변수

    while (true){
        getline(cin, dataset, '.');
        getline(cin, trash); // 이거를 안 해주면 출력초과가 난다.
        // getline 과 buffer 관련.... 내용 정리 => github comment. ★

        if(dataset.length() == 0){ // dataset에 아무것도 안 들어왔으면 종료.
            break;
        }

        if_balanced = true;
        //cout << dataset << ' ' << dataset.length() << endl;

        for(char& i:dataset){ // 배열, string 모두 범위 기반 반복 가능한 듯 !
            if(i == '(' || i == '['){
                brackets.push(i);
            }
            else if(i == ')'){
                if(brackets.empty() || brackets.top() != '('){ // empty() 인데 top을 보거나
                    if_balanced = false;
                    break;
                }
                brackets.pop(); // empty() 인데 pop()을 하는 경우 오류 발생 ★ 주의 !
            }
            else if(i == ']'){ // ☆ ')' 에 '(', ']' 에 '[' 보는 것도 처음에 혼동함.
                if(brackets.empty() || brackets.top() != '['){
                    if_balanced = false;
                    break;
                }
                brackets.pop();
            }
            else {
                // normal character
            }
        }

        if(!brackets.empty()){ if_balanced = false;} // 문자열이 끝났는데 stack 이 차 있으면 unbalanced. ☆

        cout << (if_balanced? "yes\n": "no\n");

        for(;!brackets.empty();){ // brackets stack 비워 주기.
            brackets.pop();
        }
    }
    return 0;
}