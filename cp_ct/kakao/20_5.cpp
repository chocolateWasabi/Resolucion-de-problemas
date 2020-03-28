#include <iostream>

// 제출 시작

#include <string>
#include <vector>

#include <set>
#include <utility>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int min_of_local_max = 200200200;
    int size = stones.size();

    multiset<pair<int, int>> local;
    for(int i=0;i<k;++i){
        local.insert({stones[i], i});
    }

    int local_max;
    local_max = (*local.rbegin()).first;
    min_of_local_max = local_max < min_of_local_max? local_max: min_of_local_max;

    for(int s=1,e=k;e<size;++s, ++e){
        local.erase({stones[s-1], s-1});
        local.insert({stones[e], e});

        local_max = (*local.rbegin()).first;
        min_of_local_max = local_max < min_of_local_max? local_max: min_of_local_max;
    }

    answer = min_of_local_max;
    return answer;
}

// 제출 끝

int main(){

    vector<int> stones;

    stones = {200000000, 0, 200000000, 0, 0};

    int k = 4;

    cout << solution(stones, k);

    return 0;
}