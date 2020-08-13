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
        if(childNode[int(letter-'A')] == nullptr) {
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
                now = now->getChild(*c);
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
                return 0;
            } else {
                now = now->getChild(word[i]);
            }
        }
        //return true;
        int res = 1;
        if(now->lastLetter) {
            if(!(now->isHit)) {
                // 아직 찾은 적이 없는 단어인 경우
                res |= 4; 
                now->isHit = true;
            }
            res |= 2;
        } 
        return res;
        // 리턴 값 정리: (bit index)
        // 0 - 아예 더 갈 수 없음
        // 1 - 더 갈 수는 있음
        // 2 - last letter
        // 4 - 이미 hit 한 last letter
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
    return x >= 0 && x < 4 && y >= 0 && y < 4;
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

void update(char *word, int len, int res) {
    if(res & 2) {
        if(res & 4) { // hit
            // for test - s
            //word[len] = '\0';
            //cout << word << ' ';
            // for test - e

            if(len > maxLength) {
                stringCopy(word, len);
                maxLength = len;
            } else if(len == maxLength) {
                if(lexicographicalOrder(word, maxLengthWord, len)) {
                    stringCopy(word, len);
                }
            } else {}
            score += scoreBoard[len];
            wordCount ++;
        }
    }
}


void findWord(int x, int y, int len, char* word) { // dfs 탐색 구현
    if(len >= 8) {
        return;
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

            int res = Dict.isExistWord(word, len+1);
            update(word, len+1, res);
            if(res & 1) {
                findWord(next_x, next_y, len+1, word);
            }
            visit[next_x][next_y] = 0;
            word[len+1] = '\0';
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
        //memclear(visit, sizeof(visit)/sizeof(int));
        for(int i=0;i<4;++i) {
            for(int j=0;j<4;++j) {
                word[0] = boggle[i][j];
                word[1] = '\0';

                int res = Dict.isExistWord(word, 1);
                update(word, 1, res);
                if(res & 1) {
                    memclear(visit, sizeof(visit)/sizeof(int));
                    visit[i][j] = 1;
                    findWord(i, j, 1, word);
                }
                word[0] = '\0';
            }
        }

        cout << score << ' ' << maxLengthWord << ' ' << wordCount << '\n';
        Dict.flagClear();
    }

    return 0;
}