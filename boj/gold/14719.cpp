#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w;
    vector<int> raindrop;

    cin >> h >> w;
    raindrop.resize(w);
    for(int i=0;i<w;++i) {
        cin >> raindrop[i];
    }

    int pivot = -1;
    int res = 0;
    int tmp_cnt;

    for(int i=0;i<w;++i) {
        if(pivot == -1 && raindrop[i] > 0) {
            pivot = i;
            tmp_cnt = 0;
            continue;
        }
        if(pivot != -1) {
            if(raindrop[i] >= raindrop[pivot]) {
                // pivot 갱신
                res += tmp_cnt;
                tmp_cnt = 0;
                pivot = i;
            } else {
                tmp_cnt += (raindrop[pivot] - raindrop[i]);
            }
        }
    }

    if(tmp_cnt != 0) {
        // 현재 기준값 (pivot) 보다 높은 기둥을 발견하지 못한 경우 (원래 규칙대로, 거꾸로 다시 찾기 => pivot까지)
        int pivot2 = w;
        for(int i=w-1;i>=pivot;--i) {
            if(pivot2 == w && raindrop[i] > 0) {
                pivot2 = i;
                tmp_cnt = 0;
                continue;
            }
            if(pivot2 != w) {
                if(raindrop[i] >= raindrop[pivot2]) {
                    // pivot2 갱신
                    res += tmp_cnt;
                    tmp_cnt = 0;
                    pivot2 = i;
                } else {
                    tmp_cnt += (raindrop[pivot2] - raindrop[i]);
                }
            }
        }
    }

    cout << res;
    return 0;
}