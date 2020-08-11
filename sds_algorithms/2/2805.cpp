// https://www.acmicpc.net/source/14387225
// 작년의 나보다 못 하는 나레기 반성하자
// 저녁에 각성하고 재도전 - 실버 따리에 굴복하지 말자
#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<long long> tree;

inline long long cutTree(int mid) {
    long long count = 0;
    for(auto i:tree) {
        if(i > mid) {
            count += (i - mid);
        }
    }
    return count;
}

long long getMaxHeight() {
   // parametric search
   long long l_bound, r_bound;
   long long res, mid, cut;

   l_bound = 0, r_bound = 1234567890;
   res = 0;

   for(;l_bound < r_bound;) {
       mid = (l_bound + r_bound) / 2;
       cut = cutTree(mid);
       if(cut == m) {
           res = mid;
           break;
       } else if(cut < m) {
           // 잘린 나무가 기준치에 충족을 못하면 절단기 높이를 낮춤
           r_bound = mid;
       } else { // cut > m case
           // 기준치보다 많으면, 절단기 높이를 높임 => parametric search
           // 위의 cut == m 같은 딱 떨어지는 해가 없다면, 최선의 해를 구해야 함
           if(mid > res) {
               res = mid;
           }
           l_bound = mid + 1;
       }
   }
   return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    long long data;
    for(int i=1;i<=n;++i) {
        cin >> data;
        tree.push_back(data);
    }

    cout << getMaxHeight();
    return 0;
}