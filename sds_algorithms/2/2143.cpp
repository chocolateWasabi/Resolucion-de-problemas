// 날리고 아예 다시 풀이함
// 오늘 개념 공부하고 풀었던 문제들은, 9월 초중순에 다시 풀어볼 것

// O(N^2)짜리 two pointer X O(logN)짜리 Lower/Upper Bound 찾는 parametric search
// => O(N^2 * logN) 의 복잡도, N <= 1000이라서 이 복잡도가 마지노선.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxima = 1000;
const int elemMaxima = 1000000;
int n, m;
vector<long long> a, b;
vector<long long> b_convert;
// vector<long long> b_convert {2, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 7, 7, 9, 10, 10, 10}; // for unit testing
long long t;

inline int getBound(long long target, char type) {
    int l_bound, r_bound;
    l_bound = 0, r_bound = b_convert.size();
    // parametric search에서, 구간 설정이, 결국 [l_bound, r_bound)인 것이다.
    // 그래서 구간 쪼갤 때에도, l_bound = mid + 1이고, r_bound = mid가 되는 것.
    // 근데 이것 또한, 오늘 수업 내용 그대로, 경우에 따라 다르게 적용될 수 있으므로, 
    // parametric search, binary search 같은 내용들을 다룰 때에는
    // 작성한 함수에 대해서 unit test를 꼭 수행해 볼 것.

    int mid, res = -1;
    for(;l_bound < r_bound;) {
        mid = (l_bound + r_bound) / 2;

        if(b_convert[mid] > target) {
            r_bound = mid;
        } else if(b_convert[mid] < target) {
            l_bound = mid + 1;
        } else { // 같은 값 중에서 가장 index가 작은 쪽으로 가야함
            res = mid;
            if(type == 'L') {
                r_bound = mid;
            } else if(type == 'U') {
                l_bound = mid + 1;
            } else {
                // exception case
            }
        }
    }

    if(type == 'L') {
        return res;
    } else if(type == 'U') {
        if(res != -1) {
            return res + 1;
        } else {
            return res;
        }
    } else {
        // exception case
        return -1;
    }
}

inline long long my_abs(long long data) {
    if(data < 0) {
        return -data;
    } else {
        return data;
    }
}

long long convergeVectors() {
    long long rem;
    long long count = 0;
    
    // b의 부분배열 전체 경우의 수를 다 깔아놓고, 정렬 해 놓고 parametric search 적용
    // 결국, O(N^2 + N^2 * logN)이네 그럼?
    b_convert.reserve(510000);
    for(int i=0;i<m;++i) {
        for(int j=i+1;j<=m;++j) {
            b_convert.push_back(b[j] - b[i]);
        }
    }
    sort(b_convert.begin(), b_convert.end());

    int lb, ub;
    for(int i=0;i<n;++i) { // a 배열의 첫 번째 포인터
        for(int j=i+1;j<=n;++j) { // a 배열의 두 번째 포인터
            //if(my_abs(a[j] - a[i]) < my_abs(t)) {
                rem = t - (a[j] - a[i]);
                lb = getBound(rem, 'L');
                ub = getBound(rem, 'U');
                if(lb != -1 && ub != -1) {
                    count += (ub - lb);
                    //cout << i + 1 << "~" << j << ": " << my_abs(a[j] - a[i]) << '\n';
                }
            //}
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    a.reserve(1000);
    b.reserve(1000);

    /*
    // getBound function unit test
    cout << getBound(2, 'L') << ' ';
    cout << getBound(2, 'U') << '\n';
    cout << getBound(3, 'L') << ' ';
    cout << getBound(3, 'U') << '\n';
    cout << getBound(5, 'L') << ' ';
    cout << getBound(5, 'U') << '\n';
    cout << getBound(7, 'L') << ' ';
    cout << getBound(7, 'U') << '\n';
    cout << getBound(9, 'L') << ' ';
    cout << getBound(9, 'U') << '\n';
    cout << getBound(10, 'L') << ' ';
    cout << getBound(10, 'U') << '\n';
    cout << getBound(11, 'L') << ' ';
    cout << getBound(11, 'U') << '\n';
    cout << getBound(6, 'L') << ' ';
    cout << getBound(6, 'U') << '\n';*/
    
    cin >> t >> n;
    long long tmp;
    a.push_back(0); b.push_back(0);
    for(int i=0;i<n;++i) {
        cin >> tmp;
        a.push_back(tmp);
    }
    cin >> m;
    for(int i=0;i<m;++i) {
        cin>> tmp;
        b.push_back(tmp);
    }
    for(int i=1;i<=n;++i) {
        a[i] = a[i] + a[i-1];
    }
    for(int i=1;i<=m;++i) {
        b[i] = b[i] + b[i-1];
    }

    cout << convergeVectors();
    return 0;
}