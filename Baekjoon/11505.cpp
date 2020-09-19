// BOJ 2042 연습 => 11505 곱셈... update를 make와 비슷하게 변경
#include <iostream>
using namespace std;

int n, m, k, depth, orig_n;
long long dataset[1048577];
long long segtree[2097154];
const long long divisor = 1000000007;

// 곱셈에서는 항등원이 1

long long make(int node, int left, int right) {
    if(left == right) {
        return segtree[node] = (left <= orig_n? dataset[left]: 1); //
    }
    int mid = (left + right) / 2;
    return segtree[node] = (make(node * 2, left, mid) * make(node * 2 + 1, mid + 1, right)) % divisor;
} 

long long query(int node, int left, int right, int q_left, int q_right) {
    if(right < q_left || left > q_right) {
        return 1;
    } else if(q_left <= left && right <= q_right) {
        return segtree[node];
    } else {
        int mid = (left + right) / 2;
        return  (query(node * 2, left, mid, q_left, q_right) * \
                query(node * 2 + 1, mid + 1, right, q_left, q_right)) % divisor;
    } //
}

long long update(int node, int left, int right, long long origin, long long target, int idx) {
    // 덧셈 update가 아닌 make 하는 방식으로 함수를 재구성해야 한다.
    if(left == right) {
        if(left == idx) {
            return segtree[node] = target;
        }
    }
    
    int mid = (left + right) / 2;
    /*if(idx <= mid) {
        update(node * 2, left, mid, origin, target, idx);
    } else {
        update(node * 2 + 1, mid + 1, right, origin, target, idx);
    }*/

    //

    if(left > idx || right < idx) {
        return segtree[node];
    }

    return segtree[node] = (update(node * 2, left, mid, origin, target, idx) * update(node * 2 + 1, mid + 1, right, origin, target, idx)) % divisor;

    //

    // 이 부분을 수정해야 함...
    /*if(origin) {
        segtree[node] /= origin;
    }
    segtree[node] = (segtree[node] * target) % divisor;*/
}

int getActualSize(int n) { // 
    int k = 1;
    depth = 0;
    while(k < n) {
        k <<= 1;
        depth++;
    }
    return k;
}

auto printTree = []() {
    for(int i=0;i<=2 * n;++i) {
        cout << segtree[i] << ' ';
    }
    cout << '\n';
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=1;i<=n;++i) {
        cin >> dataset[i];
    }
    orig_n = n;
    n = getActualSize(n);
    for(int i=orig_n+1;i<=n;++i) {
        dataset[i] = 1;
    }
    /*for(int i=1;i<=n;++i) {
        cout << dataset[i] << ' ';
    }*/
    //cout << '\n';
    //cout << n << '\n';
    make(1, 1, n);
    //printTree();
    for(int i=0, o, l, r;i<m+k;++i) {
        cin >> o >> l >> r;
        if(o == 1) {
            // update
            //long long diff = r - dataset[l];
            update(1, 1, n, dataset[l], r, l);
            dataset[l] = r;
        } else if(o == 2) {
            // query
            cout << query(1, 1, n, l, r) << '\n';
        }
        //printTree();
    }
    return 0;
}