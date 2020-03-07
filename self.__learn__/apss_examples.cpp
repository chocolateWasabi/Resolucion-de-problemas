#include <iostream>
#include <vector>
using namespace std;

// ch6 exhaustive search

void pick_0(int n){
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            for(int k=j+1;k<=n;++k){
                for(int l=k+1;l<=n;++l){
                    cout << "(" << i << ", " << j << ", " << k << ", "  << l << ")\n";
                }
            }
        }
    }
}

//int count = 0;
void pick_1(int n, int r, int level, int comb[]){
    if(level == r + 1){
        for(int i=1;i<=r;++i){
            cout << comb[i] << ' ';
        }
        cout << '\n';
        //count ++;
        return;
    }
    for(int i=comb[level-1]+1;i<=n;++i){
        comb[level] = i;
        pick_1(n, r, level+1, comb);
        comb[level] = 0;
    }
}

//int count2 = 0;
void pick_2(int n, vector<int>& picked, int to_pick){ // call by reference를 위해 vector<int>& 이용.
    if(to_pick == 0){
        for(auto i:picked){
            cout << i << ' ';
        }
        cout << '\n';
        //count2 ++;
        return;
    }
    int prev = picked.empty()? -1: picked.back(); // 1부터 n까지 하려면 -1대신 0
    for(int now = prev + 1; now < n; ++ now){ // 1부터 n까지 하려면 < 대신 <=
        picked.push_back(now);
        pick_2(n, picked, to_pick - 1);
        picked.pop_back();
    }
}

int main(){
    int comb[10];
    //pick_0(7);
    comb[0] = 0;
    //pick_1(7, 4, 1, comb);

    cout << "new" << endl;
    vector<int> combv;
    pick_2(7, combv, 4);

    //cout << count2 ;
    // nCr, pick_0은 r에 맞추어 반복문, pick_1은 배열, pick_2는 vector 이용.
    return 0;
}