#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
priority_queue<pair<int, int> > jewel; // value, mass 순으로 저장
vector<int> bag;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int m, v;
    for(int i=0;i<n;++i) {
        cin >> m >> v;
        jewel.push({v, m});
    }
    int c;
    for(int i=0;i<k;++i) {
        cin >> c;
        bag.push_back(c);
    }

    sort(bag.begin(), bag.end());
    long long stolenJewel = 0;

    pair<int, int> currentJewel;
    int usedBagCount = 0;
    while(!jewel.empty() && usedBagCount < bag.size()) {
        currentJewel = jewel.top();
        jewel.pop();
        for(int i=0;i<bag.size();++i) {
            if(currentJewel.second <= bag[i]) {
                stolenJewel += currentJewel.first;
                bag[i] = -1;
                ++ usedBagCount;
                break;
            }
        }
    }
    cout << stolenJewel;
    return 0;
}