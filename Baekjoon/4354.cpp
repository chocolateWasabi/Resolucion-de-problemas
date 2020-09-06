#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string text;
int failTable[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto printTable = []() {
        for(int i=0;i<text.length();++i) {
            cout << i << ' ';
        }
        cout << '\n';
    };

    while(true) {
        getline(cin, text);
        if(text == ".") {
            break;
        }
        memset(failTable, 0, sizeof(failTable));

        int i, j;
        i = 0;
        for(j=1;j<text.length();++j) {
            while(i > 0 && text[i] != text[j]) {
                i = failTable[i - 1];
                // i = failTable[i]; 로 작성하는 경우 시간초과 발생
            }
            if(text[i] == text[j]) {
                failTable[j] = ++i;
            }
        }
        //printTable();

        j = text.length() - failTable[text.length() - 1];
        if(text.length() % j == 0) {
            cout << (text.length() / j) << '\n';
        } else {
            cout << 1 << '\n';
        }
    }
    return 0;
}