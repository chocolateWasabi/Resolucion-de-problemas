// BOJ ID 16637 괄호 추가하기
// Brute force
#include <iostream>
#include <string>
using namespace std;

long long opnd[10], optr[9];
int opnd_size, max_level;

int parenthesis[10];
long long max_result;

void updateMaxResult() {
    
    /*for(int i=0;i<opnd_size;++i) {
        cout << parenthesis[i] << ' ';
    }
    cout << '\n';*/

    long long temp1, temp2;
    temp1 = opnd[0];
    temp2 = 0;

    bool processed = false;
    if(parenthesis[0] == 1) {
        processed = true;
        parenthesis[0] = parenthesis[1] = 0;
    }

    for(int i=0;i<opnd_size - 1;++i) {
        /*
        if(parenthesis[i] == 1) {   // 현재가 1, 다음도 1
            temp2 = opnd[i + 1];
            
            if(optr[i] == 1) {
                temp1 += temp2;
            } else if(optr[i] == 2) {
                temp1 -= temp2;
            } else if(optr[i] == 3) {
                temp1 *= temp2;
            }

            i += 2;
            continue;
        } */

        if(parenthesis[i + 1] == 1) {    // 다음과 다다음이 1
            if(optr[i + 1] == 1) {          // '+'
                temp2 = opnd[i + 1] + opnd[i + 2];
            } else if(optr[i + 1] == 2) {   // '-'
                temp2 = opnd[i + 1] - opnd[i + 2];
            } else if(optr[i + 1] == 3) {   // '*'
                temp2 = opnd[i + 1] * opnd[i + 2];
            }

            if(optr[i] == 1) {
                temp1 += temp2;
            } else if(optr[i] == 2) {
                temp1 -= temp2;
            } else if(optr[i] == 3) {
                temp1 *= temp2;
            }

            i += 1;
        } else {
            temp2 = opnd[i + 1];
            
            if(optr[i] == 1) {
                temp1 += temp2;
            } else if(optr[i] == 2) {
                temp1 -= temp2;
            } else if(optr[i] == 3) {
                temp1 *= temp2;
            }
        }

    }

    if(processed) {
        parenthesis[0] = parenthesis[1] = 1;
    }

    //cout << temp1 << '\n';
    max_result = temp1 > max_result? temp1: max_result;
}

void checkParenthesis(int start_pos, int current_level, int objective_level) {
    if(current_level == objective_level) {
        updateMaxResult();
        return;
    }

    for(int i=start_pos;i<opnd_size - 1;++i) {
        parenthesis[i] = parenthesis[i + 1] = 1;
        checkParenthesis(i + 2, current_level + 1, objective_level);
        parenthesis[i] = parenthesis[i + 1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    string polynomial;
    cin >> polynomial;

    if(N == 1) {
        cout << polynomial;
        return 0;
    }

    for(int i=0;i<polynomial.size();++i) {
        if(i & 1) {     // optr
            optr[i >> 1] = (polynomial[i] == '+'? 1: (polynomial[i] == '-'? 2: 3));
        } else {        // opnd
            opnd[i >> 1] = (long long)(polynomial[i] - '0');
        }
    }
    opnd_size = (polynomial.size() >> 1) + 1;
    max_level = opnd_size >> 1;
    max_result = 0x7fffffff + 1;    // minimum value (get by overflowing)

    /*for(int i=0;i<=(polynomial.size() >> 1);++i) {
        cout << opnd[i] << ' ';
    }
    cout << '\n';
    for(int i=0;i<(polynomial.size() >> 1);++i) {
        cout << optr[i] << ' ';
    }
    cout << '\n';*/

    for(int i=1;i<=max_level;++i) {
        checkParenthesis(0, 0, i);
    }

    cout << max_result;

    return 0;
}