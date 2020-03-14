#include <iostream>
#include <vector>
using namespace std;

void get_min_penalty(int level, int n, int k, vector<int>& data, vector<int>& check, int& penalty_min){
    if(level == k - 1){
        int s, t;
        t = -1;
        check.push_back(n-1);
        int count = 0;
        for(auto i:check){
            s = t + 1;
            t = i;
            if(s > t){
                break;
            }
            count += (data[t] - data[s]);
            //cout << count << ' ';
        }
        cout << endl;
        check.pop_back();
        penalty_min = count < penalty_min? count: penalty_min;
        return;
    }

    int now = check.empty()? 0: check.back() + 1;

    for(;now < n;++now){
        check.push_back(now);
        get_min_penalty(level+1, n, k, data, check, penalty_min);
        check.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> data;
    for(int i=1, tmp;i<=n;++i){
        cin >> tmp;
        data.push_back(tmp);
    }

    vector<int> check;
    int penalty_min = 99999999;
    get_min_penalty(0, n, k, data, check, penalty_min);
    cout << penalty_min;
    return 0;
}