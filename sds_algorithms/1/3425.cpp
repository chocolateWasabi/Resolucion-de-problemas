// BOJ ID 3425
#include <iostream>
#include <string>
#include <stack>
#include <string>
#include <vector>
using namespace std;

stack<long long> goStack;
vector<string> insSet;
const long long maxima = 1000000000;

inline long long my_abs(long long data) {
    return data < 0? -data: data;
}

bool executeIns(string& ins) {
    if(ins == "POP") {
        if(goStack.empty()) {
            return false;
        }
        goStack.pop();
    } else if(ins == "INV") {
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        goStack.push(-topElem);
    } else if(ins == "DUP") {
        if(goStack.empty()) {
            return false;
        }
        goStack.push(goStack.top());
    } else if(ins == "SWP") {
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        if(goStack.empty()) {
            return false;
        }
        long long top2Elem = goStack.top();
        goStack.pop();
        goStack.push(topElem);
        goStack.push(top2Elem);
    } else if(ins == "ADD") {
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        if(goStack.empty()) {
            return false;
        }
        long long top2Elem = goStack.top();
        goStack.pop();
        if(topElem + top2Elem > maxima) {
            return false;
        }
        goStack.push(topElem + top2Elem);
    } else if(ins == "SUB") {
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        if(goStack.empty()) {
            return false;
        }
        long long top2Elem = goStack.top();
        goStack.pop();
        if(+topElem - top2Elem > maxima) {
            return false;
        }
        goStack.push(-topElem + top2Elem);
    } else if(ins == "MUL") {
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        if(goStack.empty()) {
            return false;
        }
        long long top2Elem = goStack.top();
        goStack.pop();
        if(my_abs(topElem * top2Elem) > maxima) {
            return false;
        }
        goStack.push(topElem * top2Elem);
    } else if(ins == "DIV") {
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        if(goStack.empty()) {
            return false;
        }
        long long top2Elem = goStack.top();
        goStack.pop();
        if(topElem == 0) {
            return false;
        }
        goStack.push((long long)(top2Elem / topElem));
    } else if(ins == "MOD") {
        long long opr1, opr2;
        if(goStack.empty()) {
            return false;
        }
        long long topElem = goStack.top();
        goStack.pop();
        if(goStack.empty()) {
            return false;
        }
        long long top2Elem = goStack.top();
        goStack.pop();
        if(topElem < 0) {
            topElem = -topElem;
            opr1 = -1;
        } else {
            opr1 = 1;
        }
        if(top2Elem < 0) {
            top2Elem = -top2Elem;
            opr2 = -1;
        } else {
            opr2 = 1;
        }
        if(topElem == 0) {
            return false;
        }
        goStack.push((long long)(top2Elem % topElem) * (opr2));
    } else { // NUM
        string ins_modified, opnd;
        long long split_pos = ins.find("_");
        ins_modified = ins.substr(0, split_pos);
        opnd = ins.substr(split_pos+1, ins.length());
        long long opnd_longtype = stoi(opnd);
        if(opnd_longtype > maxima) {
            return false;
        }
        goStack.push(stoi(opnd));
    }
    return true;
}

void clearGoStack() {
    while(!goStack.empty()) {
        goStack.pop();
    }
}

void subPrograms() {
    long long n, vi;
    cin >> n;
    bool err_flag;

    for(;n>0;--n) {
        cin >> vi;
        clearGoStack();
        err_flag = false;
        goStack.push(vi);

        for(auto i:insSet) {
            if(!executeIns(i)) {
                cout << "ERROR\n";    
                err_flag = true;
                break;
            }
        }

        if(!err_flag) {
            if(goStack.empty()) {
                cout << "ERROR\n";
                continue;
            }
            
            long long top = goStack.top();
            goStack.pop();
            if(goStack.empty()) {
                cout << top << '\n';
            } else {
                cout << "ERROR\n";
            }
        }
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    insSet.clear();
    string ins, opnd;
    insSet.reserve(100000);
    for(;;) {
        cin >> ins;
        if(ins == "NUM") {
            cin >> opnd;
            string tmp = ins + '_' + opnd;
            insSet.push_back(tmp);
        } else if(ins == "QUIT") {
            break;
        } else if(ins == "END") {
            // 각 실행 단계로 점프
            subPrograms();
            insSet.clear();
            insSet.reserve(100000);
        } else {
            if(ins.length() == 0 || !(ins[0] >= 'A' && ins[0] <= 'Z')) {
                continue;
            }
            insSet.push_back(ins);
        }
    }

    return 0;
}