// BOJ ID 1786
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string text, pattern;
vector<int> table;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    table.reserve(1000000);
    getline(cin, text);
    getline(cin, pattern);
    table.resize(pattern.length(), 0);

    auto printTable = []() {
        for(auto k:table) {
            cout << k << ' ';
        }
        cout << '\n';
    };

    int i, j;
    i = 0;
    
    // 잘못된 실패 함수
    /*
    for(j=1;j<pattern.length();++j) {
        if(pattern[i] == pattern[j]) {
            table[j] = table[j-1] + 1;
            i++;
        } else {
            i = 0; // 아마 이게 잘못
            if(pattern[i] == pattern[j]) {
                table[j] = 1;
                i++;
            }
        }
        //printTable();
    }*/
    for(j=1;j<pattern.length();++j) {
        while(i > 0 && pattern[i] != pattern[j]) {
            i = table[i-1];
        }
        if(pattern[i] == pattern[j]) {
            table[j] = ++i;
        }
    }

    j = 0;
    vector<int> answer;
    for(i=0;i<text.length();++i) {
        if(j == pattern.length()) {
            answer.push_back(i-j+1);
        }

        while(j > 0 && text[i] != pattern[j]) {
            j = table[j - 1];
        } 
        
        if(text[i] == pattern[j]) {
            j++;
        }
    }
    if(j == pattern.length()) {
        answer.push_back(i-j+1);
    }

    cout << answer.size() << '\n';
    for(auto k:answer) {
        cout << k << ' ';
    }

    return 0;
}