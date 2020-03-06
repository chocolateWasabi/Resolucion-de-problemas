// BOJ 2294 동전 2 (DP, Knapsack 응용)
#include <iostream>
#include <set>
#define boundary 150000
using namespace std;

int min(int a, int b){
    return a < b ? a: b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    set<int> value;
    int count[2][10010];

    for(int i=0;i<2;++i){
        for(int j=0;j<10010;++j){
            count[i][j] = boundary + 10; // 최소 값 매커니즘을 위해 큰 값으로 바운더리 지정
        }
    }
    int flag = 0;

    for(int i=0, tmp;i<n;++i){
        cin >> tmp;
        if(tmp > k) continue; // 쓸모 없는 동전 버리기
        value.insert(tmp);
    }

    for(set<int>::reverse_iterator i=value.rbegin();i!=value.rend();++i){ // 역순으로 보면 복잡도 최소화
        flag ^= 1;
        for(int j=1;j<=k;++j){
            count[flag][j] = count[flag^1][j]; // 이전 값 받아오고
            if(j % (*i) == 0){ // 나누어 떨어지는 값이면 최소값 비교
                count[flag][j] = min(count[flag][j], j / (*i));
            }
            if(j > (*i) && count[flag][j-(*i)] < boundary){ 
                // j가 1부터 k(찾으려는 값) 까지 돌면서, j-(*i), 즉, 
                // 기존에 동전 교환이 가능한 경우(bounday 보다 작을 때), 저장된 수치 값에 현재의 동전을 더했을 때의 최소 값을 구한다.
                count[flag][j] = min(count[flag][j], count[flag][j-(*i)]+1);
            }
        }
        /*
        for(int j=1;j<=k;++j){
            cout << (count[flag][j] > boundary ? 0: count[flag][j]) << ' ';
        }
        cout << '\n'; */
    }
    cout << (count[flag][k] > boundary ? -1: count[flag][k]);
    return 0;
}