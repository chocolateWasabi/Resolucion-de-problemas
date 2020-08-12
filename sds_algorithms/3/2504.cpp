#include <cstdio>
#include <stack>
using namespace std;

bool isValidParenthesis(char *dat) {
    stack<char> check;
    bool isValid = true;
    for(char *c=dat;*c!='\0';++c) {
        if(*c == '(') {
            check.push('(');
        } else if(*c == '[') {
            check.push('[');
        } else if(*c == ')') {
            if(!check.empty() && check.top() == '(') {
                check.pop();
            } else {
                isValid = false;
                break;
            }
        } else if(*c == ']') {
            if(!check.empty() && check.top() == '[') {
                check.pop();
            } else {
                isValid = false;
                break;
            }
        } else {
            isValid = false;
            break;
        }
    }
    if(!check.empty()) {
        isValid = false;
    }
    return isValid;
}

int getAcc(stack<int>& calc) {
    int acc = 0;
    while(!calc.empty() && calc.top() > 0) {
        acc += calc.top();
        calc.pop();
    }
    return acc;
}

int main() {
    stack<int> calc;
    char dat[31];

    // gets_s(dat, 30); // g++에서 secure coding 지원 안함???????
    gets(dat);

    // () => -1
    // [] => -2
    
    if(!isValidParenthesis(dat)) {
        printf("%d", 0);
        return 0;
    }

    int tmp, acc;
    for(char *c=dat;*c!='\0';++c) {
        if(*c == '(') {
            calc.push(-1);
        } else if(*c == '[') {
            calc.push(-2);
        } else if(*c == ')') {
            acc = 0;
            acc = getAcc(calc);
            if(!calc.empty() && calc.top() == -1) {
                calc.pop();
                if(acc) {
                    calc.push(acc * 2);
                } else {
                    calc.push(2);
                }
            }
        } else if(*c == ']') {
            acc = 0;
            acc = getAcc(calc);
            if(!calc.empty() && calc.top() == -2) {
                calc.pop();
                if(acc) {
                    calc.push(acc * 3);
                } else {
                    calc.push(3);
                }
            }
        } else {
            // exception case
        }
    }

    printf("%d", getAcc(calc));
    return 0;
}