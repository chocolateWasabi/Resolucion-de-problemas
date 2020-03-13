// 처음에 짠 코드
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
    while (true){
        for(;!brackets.empty();){
            brackets.pop();
        }
        if_balanced = true;
        getline(cin, dataset);
    
        if(!dataset.compare(".")){
            break;
        }

        for(char& i:dataset){
            if(i == '(' || i == '['){
                brackets.push(i);
            }
            else if(i == ')' || i == ']'){
                if(brackets.empty() || brackets.top() != i){
                    if_balanced = false;
                    break;
                }
                brackets.pop();
            }
            else {
                // normal character
            }
        }

        cout << (if_balanced? "yes\n": "no\n");
    }
    return 0;
}