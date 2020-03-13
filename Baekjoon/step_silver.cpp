/*
// BOJ ID 15652
#include <iostream>
#include <vector>
using namespace std;

void pick(int n, int mtogo, vector<int>& picked){
    if(mtogo == 0){
        for(auto i:picked){
            cout << i << ' ';
        }
        cout << '\n';
        return ;
    }
    int now;
    if(picked.empty() == true){
        now = 1;
    }
    else {
        now = picked.back();
    }
    for(int i=now;i<=n;++i){
        picked.push_back(i);
        pick(n, mtogo-1, picked);
        picked.pop_back();
    }
}

int main(){
    int n, m;
    vector<int> picked;

    cin >> n >> m;
    pick(n, m, picked);
    return 0;
} */
/*
// BOJ ID 1912
#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a: b;
}

int main(){
    int n;
    cin >> n;
    long long local_min, local_max, accumulation, candidate;
    local_min = local_max = accumulation;
    candidate = -9999999999;
    for(int tmp;n>0;--n){
        cin >> tmp;
        accumulation += tmp;
        if(accumulation < local_min){ // local 최소값 들어오면 local 최대값 초기화, 후보 선택 보류.
            local_min = accumulation;
            local_max = local_min;
        }
        if(accumulation > local_max){ // local 최대값 들어오면 후보 선택.
            local_max = accumulation;
            candidate = max(local_max-local_min, candidate);
        }
        candidate = max(candidate, tmp); // 지금 것 하나만 가져가는 경우.
        //cout << "lmin: " << local_min << "lmax: " << local_max << "cand: " << candidate << endl;
    }
    cout << candidate;
    return 0;
}*/

/*
// BOJ ID 10773
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> zerothatout;
    int k;

    cin >> k;
    for(int i=1, tmp;i<=k;++i){
        cin >> tmp;
        if(tmp != 0){
            zerothatout.push(tmp);
        }
        else{
            zerothatout.pop();
        }
    }

    int sum = 0;
    for(;!zerothatout.empty();){
        sum += zerothatout.top();
        zerothatout.pop();
    }

    cout << sum;
}*/

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