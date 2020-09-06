// 절반 잘라서 붙이는 아이디어엔 문제가 있음
// 일단 보류
#include <iostream>
#include <string>
using namespace std;

int len, failTable[2000000];
string ad;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> len;
    cin >> ad;

    ad += ad.substr(0, int((len + 1) / 2));
    len = ad.length();

    int i, j;
    i = 0;

    auto printTable = []() {
        cout << ad << '\n';
        for(int p=0;p<len;++p) {
            cout << failTable[p] << ' ';
        }
        cout << '\n';
    };

    for(j=1;j<len;++j) {
        while(i > 0 && ad[i] != ad[j]) {
            i = failTable[i - 1];
        }
        if(ad[i] == ad[j]) {
            failTable[j] = ++i;
        }
    }
    printTable();

    return 0;
}