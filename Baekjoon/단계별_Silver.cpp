// BOJ ID 15650
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
        now = 0;
    }
    else {
        now = picked.back();
    }
    for(int i=now+1;i<=n;++i){
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
}