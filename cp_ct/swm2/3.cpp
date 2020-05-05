#include <iostream>
#include <set>
#include <utility>
using namespace std;

int n;
set<pair<long long, pair<int, int> > > channeling; // < 현재 channeling, < 몇 번째 인덱스, 시작/끝 > >
int check[100001];
set<pair<int, int> > result;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    long long s, e;
    for(int i=1;i<=n;++i){
        cin >> s >> e;
        channeling.insert({s, {i, 0}});
        channeling.insert({e, {i, 1}});
    }

    int idx = 1;
    check[0] = -1;
    for(auto i:channeling){
        if(i.second.second == 0){ // 가산
            check[idx] = check[idx-1] + 1;
            result.insert({i.second.first, check[idx]});
        }
        else if(i.second.second == 1){ // 감산
            check[idx] = check[idx-1] - 1;
        }
        ++ idx;
    }

    for(auto i:result){
        cout << i.second << '\n';
    }

    return 0;
}