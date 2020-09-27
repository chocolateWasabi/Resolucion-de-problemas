// BOJ ID 1735
/*
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(!b) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1;
    cin >> a2 >> b2;
    int a, b;
    b = b1 * b2;
    a = b1 * a2 + b2 * a1;
    int g = gcd(a, b);
    cout << (a / g) << ' ' << (b / g);
    return 0;
}*/

// BOJ ID 11286
/*
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> ipair;
auto cmp = [](const ipair& lhs, const ipair& rhs) {
    if(lhs.second == rhs.second) {
        return lhs.first > rhs.first;
    } else {
        return lhs.second > rhs.second;
    }
};
priority_queue<ipair, vector<ipair>, decltype(cmp) > heap(cmp);

int my_abs(int k) {
    return k > 0? k: -k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int t;n>0;--n) {
        cin >> t;
        if(t) {
            heap.push({t, my_abs(t)});
        } else {
            if(!heap.empty()) {
                ipair top = heap.top();
                cout << top.first << '\n';
                heap.pop();
            } else {
                cout << 0 << '\n';
            }
        }
    }
    return 0;
}*/

/*
// BOJ ID 11725
#include <iostream>
#include <queue>
using namespace std;

class Edge {
public:
    Edge *nextOne, *revLink;
    int node;
    Edge() {
        nextOne = revLink = nullptr;
        node = 0;
    }
};

const int nMax = 100001;
int n;
Edge *tree[nMax];
int visit[nMax];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;++i) {
        tree[i] = new Edge;
    }
    for(int i=1;i<n;++i) {
        int a, b;
        cin >> a >> b;
        Edge *link1, *link2;
        link1 = new Edge;
        link2 = new Edge;
        link1->node = b;
        link2->node = a;
        link1->revLink = link2;
        link2->revLink = link1;
        link1->nextOne = tree[a]->nextOne;
        tree[a]->nextOne = link1;
        link2->nextOne = tree[b]->nextOne;
        tree[b]->nextOne = link2;
    }

    queue<int> bfs;
    bfs.push(1);
    visit[1] = 1;
    while(!bfs.empty()) {
        int now = bfs.front();
        bfs.pop();

        for(Edge *iterator=tree[now]->nextOne;iterator!=nullptr;iterator=iterator->nextOne) {
            if(visit[iterator->node]) {
                continue;
            }
            bfs.push(iterator->node);
            visit[iterator->node] = now;
        }
    }
    for(int i=2;i<=n;++i) {
        cout << visit[i] << '\n';
    }
    return 0;
}*/

// BOJ ID 5639 - BST (배열 버전은 최악의 경우를 처리할 수 없음 - skewed)
/*
#include <cstdio>
using namespace std;

const int nMax = 16385;
int tree[nMax];

void postfix(int idx) {
    if(tree[idx * 2]) {
        postfix(idx * 2);
        printf("%d\n", tree[idx * 2]);
    }
    if(tree[idx * 2 + 1]) {
        postfix(idx * 2 + 1);
        printf("%d\n", tree[idx * 2 + 1]);
    }
}

int main() {
    int key, idx = 0;
    while(~scanf("%d", &key)) {
        if(!idx) {
            idx = 1;
            tree[idx] = key;
            continue;
        }
        idx = 1;
        while(tree[idx]) {
            if(key < tree[idx]) {
                idx *= 2;
            } else {
                idx = idx * 2 + 1;
            }
        }
        tree[idx] = key;
    }
    postfix(1);
    printf("%d", tree[1]);
    return 0;
}*/

// BOJ ID 5639
/*
#include <iostream>
using namespace std;

class Tree {
public:
    Tree *parent, *l_child, *r_child;
    int key;
    Tree() {
        parent = l_child = r_child = nullptr;
        key = 0;
    }
};

Tree *root;

void postfix(Tree *idx) {
    if(idx->l_child != nullptr) {
        postfix(idx->l_child);
        cout << idx->l_child->key << '\n';
    }
    if(idx->r_child != nullptr) {
        postfix(idx->r_child);
        cout << idx->r_child->key << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    root = new Tree;
    root->parent = root;
    int key;
    Tree *idx;
    while(cin >> key) {
        if(!root->key) {
            root->key = key;
            continue;
        }
        idx = root;
        char whichChild = '.';
        while(true) {
            if(key < idx->key) {
                if(idx->l_child != nullptr) {
                    idx = idx->l_child;
                } else {
                    whichChild = 'L';
                    break;
                }
            } else {
                if(idx->r_child != nullptr) {
                    idx = idx->r_child;
                } else {
                    whichChild = 'R';
                    break;
                }
            }
        }
        Tree *newNode = new Tree;
        newNode->parent = idx;
        newNode->l_child = newNode->r_child = nullptr;
        newNode->key = key;
        if(whichChild == 'L') {
            idx->l_child = newNode;
        } else if(whichChild == 'R') {
            idx->r_child = newNode;
        } else {}
    }

    postfix(root);
    cout << root->key;
    return 0;
}*/

// BOJ ID 15654, 15655, 15656, 15657, 15664, 15665, 15666
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<int> nums, series;
int visit[10];
set<vector<int> > redundant;

void comb(int level) {
    if(level == m) {
        redundant.insert(series);
        return;
    }
    for(int i=0;i<n;++i) {
        //if(!visit[i]) {// && 
            if(level == 0 || nums[i] >= series[level-1]) {
                visit[i] = 1;
                series.push_back(nums[i]);
                comb(level + 1);
                series.pop_back();
                visit[i] = 0;
            }
        //}
    }
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    cin >> n >> m;
    for(int i=0, t;i<n;++i) {
        cin >> t;
        nums.push_back(t);
    }
    sort(nums.begin(), nums.end());
    comb(0);
    for(auto i:redundant) {
        for(auto j:i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
    return 0;
}*/

// BOJ ID 18917
/*
#include <iostream>
#include <map>
using namespace std;

map<int, int> countt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    int op, opnd;
    countt[0] ++;
    long long summ, xorr;
    summ = xorr = 0;
    for(;m>0;--m) {
        cin >> op;
        switch(op) {
        case 1:
            cin >> opnd;
            countt[opnd] ++;
            summ += opnd;
            xorr ^= opnd;
            break;
        case 2:
            cin >> opnd;
            countt[opnd] --;
            summ -= opnd;
            xorr ^= opnd;
            break;
        case 3:
            cout << summ << '\n';
            break;
        case 4:
            cout << xorr << '\n';
            break;
        default:
            break;
        }
    }
    return 0;
}*/

// BOJ ID 10815
/*
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    set<int> sanggeun;

    cin >> n;
    for(int t;n>0;--n) {
        cin >> t;
        sanggeun.insert(t);
    }

    int m;
    cin >> m;
    for(int t;m>0;--m) {
        cin >> t;
        if(sanggeun.find(t) == sanggeun.end()) {
            cout << 0 << ' ';
        } else {
            cout << 1 << ' ';
        }
    }
    return 0;
}*/

// BOJ ID 1406
/*
#include <iostream>
#include <string>
using namespace std;

class DLList {
public:
    DLList *left, *right;
    char c;
    DLList() {
        this->left = this->right = nullptr;
        c = '\0';
    }
};

DLList *head, *tail;

auto print = []() {
    for(DLList *ptr = head->right;ptr != tail;ptr=ptr->right) {
        cout << ptr->c;
    }
    //cout << '\n';
};

string str;
void makeStrList() {
    DLList *ptr = head;
    
    for(auto c:str) {
        DLList *tmp = new DLList;
        tmp->c = c;
        tmp->left = ptr;
        tmp->right = tail;
        tail->left = tmp;
        ptr->right = tmp;
        ptr = ptr->right;
    }

    //print();
}

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    head = new DLList;
    tail = new DLList;
    head->right = tail;
    head->c = '(';
    tail->left = head;
    tail->c = ')';

    getline(cin, str);
    makeStrList();
    int m;
    string tmp;
    getline(cin, tmp);
    m = stoi(tmp);

    DLList *ptr = tail;
    string op;
    for(int i=0;i<m;++i) {
        getline(cin, op);
        if(op == "L"){
            if(ptr->left != head) {
                ptr = ptr->left;
            }
        } else if(op == "D") {
            if(ptr->right != nullptr) {
                ptr = ptr->right;
            }
        } else if(op == "B") {
            if(ptr->left != head) {
                DLList *tmp = ptr->left;
                ptr->left = ptr->left->left;
                ptr->left->right = ptr;
                delete tmp;
            }
        } else {
            DLList *tmp = new DLList;
            tmp->c = op[op.find(' ')+1];
            tmp->left = ptr->left;
            tmp->right = ptr;
            ptr->left->right = tmp;
            ptr->left = tmp;
        }
        //print();
    }
    print();
    return 0;
}*/

// BOJ ID 10867
/*
#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    set<int> dataset;
    cin >> n;
    for(int t;n>0;--n) {
        cin >> t;
        dataset.insert(t);
    }

    for(auto i:dataset) {
        cout << i << ' ';
    }
    return 0;
}*/

// BOJ ID 6603
/*
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void makeCase(vector<int>& lotto, int level, int visit[], vector<int>& res) {
    if(level == 6) {
        for(auto i:res) {
            cout << lotto[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=!level?0:res.back();i<=lotto.size()-6+level;++i) {
        if(!visit[i]) {
            res.push_back(i);
            visit[i] = 1;
            makeCase(lotto, level+1, visit, res);
            visit[i] = 0;
            res.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> lotto, res;
    int visit[15];
    while(true) {
        cin >> n;
        if(!n) {
            break;
        }
        lotto.clear();
        memset(visit, 0, sizeof(visit));
        for(int i=0, t;i<n;++i) {
            cin >> t;
            lotto.push_back(t);
        }
        makeCase(lotto, 0, visit, res);
        cout << '\n';
    }

    return 0;
}*/

// BOD ID 1182 - WA (부분수열의 정의가 연속된 숫자만을 나타내는게 아니라고 함)
/*
#include <iostream>
using namespace std;

int n, s;
int dat[21][2];

int main() {
    cin >> n >> s;
    for(int i=1;i<=n;++i) {
        cin >> dat[i][0];
        dat[i][1] = dat[i][0] + dat[i-1][1];
    }
    int count = 0;
    for(int i=n;i>=1;--i) {
        for(int j=i;j<=n;++j) {
            if(dat[j][1] - dat[j-i][1] == s) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}*/

// BOJ ID 9095
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    int summ[15] = {0, 1, 2, 4};
    for(int i=4;i<=11;++i) {
        summ[i] = summ[i-1] + summ[i-2] + summ[i-3];
    }

    for(int t=1, tt;t<=T;++t) {
        cin >> tt;
        cout << summ[tt] << endl;
    }
    return 0;
}