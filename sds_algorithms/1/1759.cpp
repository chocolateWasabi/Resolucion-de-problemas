#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int l, c;
vector<pair<char, bool> > crypto;

inline bool isVowel(char t) {
    if( t == 'a' ||
        t == 'e' ||
        t == 'i' ||
        t == 'o' ||
        t == 'u') {return true; }
    return false;
}

void findPassword(vector<bool>& visit, int vCnt, int cCnt, int length, int prev) {
    if(length == l) {
        if(vCnt >= 1 && cCnt >= 2) {
            for(int i=0;i<c;++i) {
                if(visit[i]) {
                    cout << crypto[i].first;
                }
            }
            cout << '\n';
        }
    }

    for(int i=prev + 1;i<c;++i) {
        if(!visit[i]) {
            visit[i] = true;
            findPassword(visit, crypto[i].second? vCnt+1: vCnt, crypto[i].second? cCnt: cCnt+1, length+1, i);
            visit[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> c;
    char tempInput;
    for(int i=0;i<c;++i) {
        cin >> tempInput;
        crypto.push_back({tempInput, isVowel(tempInput)});
    }
    sort(crypto.begin(), crypto.end(), [](const pair<char, bool>& left, const pair<char, bool>& right) {
        return left.first < right.first;
    });

    vector<bool> visit(c, 0);
    findPassword(visit, 0, 0, 0, -1);

    return 0;
}