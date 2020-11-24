// BOJ ID 13305 AC
// cost sum using greedy algorithm
#include <iostream>
using namespace std;

unsigned long long n, edge[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(unsigned long long i=0;i<n-1;++i) {
        cin >> edge[i];
    }

    unsigned long long local_min, tmp_input, cost_sum = 0;
    cin >> local_min;
    for(unsigned long long i=0;i<n-1;++i) {
        //
        cost_sum += local_min * edge[i];
        //
        cin >> tmp_input;
        local_min = tmp_input < local_min? tmp_input: local_min;
    }

    cout << cost_sum;
    return 0;
}