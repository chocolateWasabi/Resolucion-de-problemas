#include <iostream>

// 제출 start

#include <string>
#include <vector>
#include <cstring>

#include <set>

using namespace std;

int if_match(string& banned, string& user){
    if(user.length() != banned.length()){
        return 0;
    }

    int len = user.length();
    for(int i=0;i<len;++i){
        if(user[i] != banned[i]){
            if(banned[i] != '*'){
                return 0;
            }
        }
    }

    return 1;
}

int check[10];
set<vector<int> > checkset;
void find(int b2u[10][10], int b, int bn, int un){
    if(b == bn){
        vector<int> tmp;
        tmp.clear();
        for(int i=0;i<10;++i){
            if(check[i]){
                tmp.push_back(i);
            }
        }
        if(tmp.size() == bn){
            checkset.insert(tmp);
        }
        return;
    }
    for(int j=0;j<un;++j){
        if(b2u[b][j] == 1 && check[j] == 0){
            check[j] = 1;
            find(b2u, b + 1, bn, un);
            check[j] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;

    int banned2user[10][10];
    memset(banned2user, 0, sizeof(banned2user));
    
    int b_n = banned_id.size(), u_n = user_id.size();
    for(int i=0;i<b_n;++i){
        for(int j=0;j<u_n;++j){
            banned2user[i][j] = if_match(banned_id[i], user_id[j]);
        }
    }

    find(banned2user, 0, b_n, u_n);
    for(auto i:checkset){
        if(i.size() == b_n){
            answer ++;
        }
    }
    return answer;
}


// 제출 end

int main(){
    vector<string> user_id, banned_id;

    /*string a, b;
    while (true){
        cin >> a >> b;
        cout << (if_match(a, b)? "true": "false") << endl;
    }*/

    // 1st tc
    user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    banned_id = {"fr*d*", "abc1**"};

    cout << solution(user_id, banned_id) << endl;

    // 2nd tc
    user_id.clear();
    banned_id.clear();
    user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    banned_id = {"*rodo", "*rodo", "******"};

    cout << solution(user_id, banned_id) << endl;

    // 3rd tc
    user_id.clear();
    banned_id.clear();
    user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    banned_id = {"fr*d*", "*rodo", "******", "******"};

    cout << solution(user_id, banned_id) << endl;

    return 0;
}