// 길이가 k인 문자열의 총 부분 문자열의 수 = (k+1 2)
// k의 최대 값 = 400, 결국 총 경우의 수 = 약 8만
// 올림해서 10만 개의 index를 가진 string type의 heap을 구성하면 된다.
// 메모리? 약 30mb 소요 (메모리 제한 256mb) => 충분 !

#include <set>
#include <string>
#include <iostream>
using namespace std;

set<string> dataset;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int order;
    string my_string;
    for(int t=1;t<=T;++t){
        dataset.clear();
        cin >> order;
        cin >> my_string;
        for(int i=0;i<my_string.length();++i){
            for(int j=0;j<my_string.length()-i;++j){
                dataset.insert(my_string.substr(j, i+1));
            }
        }

        int new_count = 0;
        cout << '#' << t << ' ' ;
        for(auto i:dataset){
            ++ new_count;
            if(new_count == order){
                cout << i << '\n';
                break;
            }
        }
        if(order > dataset.size()){
            cout << "none\n";
        }
    }
    return 0;
}