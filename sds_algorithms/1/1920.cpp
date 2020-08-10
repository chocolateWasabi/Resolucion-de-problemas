#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define maxima 100000
int n, m;
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.reserve(maxima);
    for(int i=0, tmp;i<n;++i) {
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    cin >> m;
    for(int i=0, tmp;i<m;++i) {
        cin >> tmp;
        cout << binary_search(a.begin(), a.end(), tmp) << '\n';
    }

    return 0;
}