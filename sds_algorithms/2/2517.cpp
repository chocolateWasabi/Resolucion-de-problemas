// merge sort를 응용한 inversion count를 이용한 문제
// indexed tree 이용해서 풀 수도 있다고 하는데 추후 다시 풀어봐야 할 듯
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define maxima 500000

int n;
vector<pair<int, int> > athletes; // {선수 등수, 계산된 변환 index}
vector<pair<int, int> > merging; // {aO index, 현재 처리하는 값}
vector<pair<int, int> > temp;
    
void conqure(int l_bound, int r_bound) {
    // merging
    int mid = (l_bound + r_bound) / 2;
    int i, j;
    i = l_bound;
    j = mid+1;

    temp.clear();

    int ip, jp;
    for(;i<=mid && j<=r_bound;) {
        ip = athletes[merging[i].first].first;
        jp = athletes[merging[j].first].first;

        if(ip < jp) {
            temp.push_back({merging[i].first, 0});
            ++i;
        } else { // 중복되는 케이스 없음
            temp.push_back({merging[j].first, i-l_bound});
            ++j;
        }
    }
    while(i <= mid) { // 뒤에 오는게 먼저 다 빠진 경우
        temp.push_back({merging[i].first, 0});
        ++i;
    }
    while(j <= r_bound) { // 앞 블록이 먼저 다 빠진 경우
        temp.push_back({merging[j].first, mid-l_bound+1});
        ++j;
    }

    // 후처리
    for(int k=l_bound;k<=r_bound;++k) {
        merging[k] = temp[k-l_bound];
        if(merging[k].second) {
            athletes[merging[k].first].second += merging[k].second;
        }
    }
}

void divide(int l_bound, int r_bound) {
    if(l_bound == r_bound) {
        return;
    }

    int mid = (l_bound + r_bound) / 2;
    divide(l_bound, mid);
    divide(mid+1, r_bound);
    conqure(l_bound, r_bound);
    /*for(int i=l_bound;i<=r_bound;++i) {
        cout << "{" << athletes[merging[i].first].first << "," << athletes[merging[i].first].second << "} ";
    }
    cout << '\n';*/
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    athletes.reserve(maxima);
    merging.reserve(maxima);
    temp.reserve(maxima);
    
    cin >> n;
    for(int i=0, t;i<n;++i) {
        cin >> t;
        athletes.push_back({t, 0});
        merging.push_back({i, 0});
    }

    divide(0, n-1);
    for(int i=0;i<n;++i) {
        cout << (i + 1 - athletes[i].second) << '\n';
    }
    return 0;
}