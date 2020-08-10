#include <iostream>
#include <string>
using namespace std;

int n, k;
int alphabet[26];
int words[55][26];
int max_level, max_count;

inline int countReadableWords() {
    int count = 0;
    bool isReadable;
    for(int i=0;i<n;++i) {
        isReadable = true;
        for(int j=0;j<int('z'-'a'+1);++j) {
            if(words[i][j] && !alphabet[j]) {
                isReadable = false;
                break;
            }
        }
        if(isReadable) {
            ++ count;
        }
    }
    return count;
}

void search(int idx, int level) {
    if(level == max_level) {
        int count = countReadableWords();
        max_count = count > max_count? count: max_count;
        return;
    }

    for(int i=idx+1;i<int('z'-'a'+1);++i) {
        if(!alphabet[i]) {
            alphabet[i] = 1;
            search(i, level + 1);
            alphabet[i] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // anta, tica
    // a, n, t, i, c는 필수 (k가 최소 5 이상이 되어야 기본적인 단어 읽기 가능)
    alphabet[int('a'-'a')]
    = alphabet[int('n'-'a')]
    = alphabet[int('t'-'a')]
    = alphabet[int('i'-'a')]
    = alphabet[int('c'-'a')] = 1;

    cin >> n >> k;
    string word;
    for(int i=0;i<n;++i) {
        cin >> word;
        for(auto j:word) {
            words[i][int(j-'a')] = 1;
        }
    }

    if(k >= 5) {
        // find
        max_level = k - 5;
        if(!max_level) {
            search(0, 0);
        }
        for(int i=0;i<int('z'-'a'+1);++i) {
            if(!alphabet[i]) {
                alphabet[i] = 1;
                search(i, 1);
                alphabet[i] = 0;
            }
        }
        cout << max_count;
    }
    else {
        cout << 0;
    }

    return 0;
}