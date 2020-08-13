// Boggle - using Trie structure
#include <iostream>
using namespace std;

const int alphabetSize = int('z' - 'a') + 1;

// 강사님의 조언: isHit 추가 => 점수 카운팅을 한 번만 하기 때문!
class TrieInstance {
private:
    char letter;
    TrieInstance *childNode[26];
public:
    bool lastLetter, isHit;
    void setLetter(char letter) {
        this->letter = letter;
    }
    char getLetter() {
        return letter;
    }
    bool isExistChild(char letter) {
        if(childNode[letter] == nullptr) {
            return false;
        } else {
            return true;
        }
    }
    TrieInstance() {
        for(int i=0;i<alphabetSize;++i) {
            childNode[i] = nullptr;
        }
        letter = '_';
        // lastLetter = true; //
        lastLetter = isHit = false;
    }
    void addChild(char letter) {
        TrieInstance *newLetter = new TrieInstance;
        newLetter->setLetter(letter);
        childNode[int(letter-'A')] = newLetter;
        // lastLetter = false;
    }
    TrieInstance* getChild(char letter) {
        return childNode[int(letter-'A')];
    }
    /*bool isLastLetter() {
        return lastLetter;
    }*/
};

class Trie {
private:
    TrieInstance *root;
    void _flagClear(TrieInstance *now);
public:
    Trie() {
        root = new TrieInstance;
    }
    void addWord(char *word) {
        TrieInstance *now = root;
        for(char *c=word;*c!='\0';++c) {
            if(now->isExistChild(*c)) {
                now = now->getChild(*c);
            } else {
                now->addChild(*c);
            }
            if(*(c+1) == '\0') {
                now->lastLetter = true;
            }
        }
    }
    int isExistWord(char *word, int len) {
        TrieInstance *now = root;
        for(int i=0;i<len;++i) {
            if(!(now->isExistChild(word[i]))) {
                return false;
            }
        }
        //return true;
        int res = 0;
        if(now->lastLetter) {
            if(!(now->isHit)) {
                res |= 2;
            } else { 
                now->isHit = true;
            }
            res |= 1;
        } 
        return res;
        // 중간에서 끝나면 결국 없는 단어랑 같다. (주의!!!)
    }
    void flagClear() {
        // isHit Clear
        TrieInstance *now = root;
        _flagClear(now);
    }
};

void Trie::_flagClear(TrieInstance *now) {
    now->isHit = false;
    for(int i=0;i<alphabetSize;++i) {
        if(now->isExistChild(char(i+'A'))) {
            _flagClear(now->getChild(char(i+'A')));
        }
    }
}

const int dx[] = {0, 0, +1, +1, +1, -1, -1, -1};
const int dy[] = {-1, +1, -1, 0, +1, -1, 0, +1};

bool inRange(int x, int y) {
    return x >= 0 && x <= 4 && y >= 0 && y <= 4;
}

void memclear(int (*target)[5], int size) {
    for(int i=0;i<size;++i) {
        target[0][i] = 0;
    }
}

char boggle[5][5];
int visit[5][5];
Trie Dict;

const int scoreBoard[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

bool lexicographicalOrder(char *word1, char *word2, int len) {
    // true = word1, false = word2
    for(int i=0;i<len;++i) {
        if(word1[i] < word2[i]) {
            return true;
        } else if(word1[i] > word2[i]) {
            return false;
        } else {} // exception
    }
    return true;
}

int maxLength, score, wordCount;
char maxLengthWord[9];

void stringCopy(char *src, int len) {
    for(int i=0;i<len;++i) {
        maxLengthWord[i] = src[i];
    }
    maxLengthWord[len] = '\0';
}


void findWord(int x, int y, int len, char* word) { // dfs 탐색 구현
    if(len >= 8) {
        return;
    }

    // word checking
    int res = Dict.isExistWord(word, len);
    if(!(res & 2) && (res & 1)) { // hit
        if(len > maxLength) {
            stringCopy(word, len);
            maxLength = len;
            score += scoreBoard[len];
            wordCount ++;
        } else if(len == maxLength) {
            if(lexicographicalOrder(word, maxLengthWord, len)) {
                stringCopy(word, len);
            }
            score += scoreBoard[len];
            wordCount ++;
        } else {}
    }

    // find next
    int next_x, next_y;
    for(int dir=0;dir<8;++dir) {
        next_x = x + dx[dir];
        next_y = y + dy[dir];
        if( inRange(next_x, next_y) && !visit[next_x][next_y]) {
            word[len] = boggle[next_x][next_y];
            word[len+1] = '\0';
            visit[next_x][next_y] = 1;
            findWord(next_x, next_y, len+1, word);
            visit[next_x][next_y] = 0;
            word[len] = '\0';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w;
    char word[9];
    cin >> w;
    for(int i=0;i<w;++i) {
        cin >> word;
        Dict.addWord(word);
    }
    int b;
    cin >> b;
    for(;b>0;--b) {
        for(int i=0;i<4;++i) {
            cin >> boggle[i];
        }
        //cin >> // 빈 칸 입력

        score = maxLength = wordCount = 0;
        maxLengthWord[0] = '\0';
        memclear(visit, sizeof(visit)/sizeof(int));
        for(int i=0;i<4;++i) {
            for(int j=0;j<4;++j) {
                word[0] = '\0';
                findWord(i, j, 0, word);
            }
        }

        cout << score << ' ' << maxLengthWord << ' ' << wordCount << '\n';
        Dict.flagClear();
    }

    return 0;
}