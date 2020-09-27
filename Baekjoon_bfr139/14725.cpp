// TRIE 문제, AC
#include <iostream>
#include <string>
#include <map>
using namespace std;

class AntHouse {
public:
    map<string, AntHouse*> child;
    int level;
    AntHouse() {
        level = 0;
        child.clear();
    }
};
AntHouse *entrance;
void dfs(AntHouse *current) {
    if((current->child).size() == 0) {
        return;
    }
    for(auto i:(current->child)) {
        for(int j=0;j<current->level;++j) {
            cout << "--";
        }
        cout << i.first << '\n';
        dfs(i.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    entrance = new AntHouse;
    int n, k;
    string nest;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> k;
        AntHouse *it = entrance;
        for(int j=0;j<k;++j) {
            cin >> nest;
            auto tmpPos = (it->child).find(nest);
            if(tmpPos == (it->child).end()) {
                AntHouse *newNest = new AntHouse;
                newNest->level = j + 1;
                (it->child)[nest] = newNest;
                it = newNest;
            } else {
                it = tmpPos->second;
            }
        }
    }
    dfs(entrance);

    return 0;
}