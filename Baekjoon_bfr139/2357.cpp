#include <iostream>
#include <vector>
using namespace std;

typedef long long lli;
typedef vector<lli> vec;
typedef pair<lli, lli> lli_pair;
typedef vector<pair<lli, lli> > pair_vec;
const int maxima = 131073;

const lli_pair default_pair = {1234567890, 0};

lli min(lli a, lli b) {
    return a < b? a: b;
}

lli max(lli a, lli b) {
    return a > b? a: b;
}

lli_pair make(vec& dataset, pair_vec& segtree, int node, int left, int right, int orig_n) {
    if(left == right) {
        //cout << dataset[left] << '.';
        return segtree[node] = (left <= orig_n? make_pair(dataset[left], dataset[left]): default_pair);
    }
    int mid = (left + right) / 2;
    lli_pair current_node, l_child, r_child;
    l_child = make(dataset, segtree, node * 2, left, mid, orig_n);
    r_child = make(dataset, segtree, node * 2 + 1, mid + 1, right, orig_n);
    current_node = {min(l_child.first, r_child.first), max(l_child.second, r_child.second)};
    return segtree[node] = current_node;
};

lli_pair query(pair_vec& segtree, int node, int left, int right, int q_left, int q_right) {
    if(q_left > right || q_right < left) {
        return default_pair;
    } else if(q_left <= left && right <= q_right) {
        return segtree[node]; 
    } else {
        int mid = (left + right) / 2;
        lli_pair current_node, l_child, r_child;
        l_child = query(segtree, node * 2, left, mid, q_left, q_right);
        r_child = query(segtree, node * 2 + 1, mid + 1, right, q_left, q_right);
        current_node = {min(l_child.first, r_child.first), max(l_child.second, r_child.second)};
        return current_node;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vec dataset;
    pair_vec segtree;
    cin >> n >> m;
    dataset.reserve(maxima);
    segtree.reserve(maxima * 2);
    int orig_n;

    auto get2n = [](int num) {
        int k = 1;
        while(k < num) {
            k <<= 1;
        }
        return k;
    };
    orig_n = n;
    n = get2n(n) + 1;

    dataset.resize(n, 0);
    for(int i=1;i<=orig_n;++i) {
        cin >> dataset[i];
    }
    segtree.resize(2 * n, default_pair);

    make(dataset, segtree, 1, 1, n, orig_n);
    
    /*cout << "pp" << '\n';
    for(int i=1;i<=2*n;++i) {
        cout << segtree[i].first << ' ' << segtree[i].second << '\n';
    }*/
    for(int i=0, a, b;i<m;++i) {
        cin >> a >> b;
        lli_pair res = query(segtree, 1, 1, n, a, b);
        cout << res.first << ' ' << res.second << '\n';
    }
    return 0;
}