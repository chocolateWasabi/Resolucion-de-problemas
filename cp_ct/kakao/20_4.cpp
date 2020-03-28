#include <iostream>

// 제출 시작

#include <string>
#include <vector>

#include <set>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    set<long long> check;
    check.clear();

    for(auto i:room_number){
        if(check.find(i) == check.end()){
            answer.push_back(i);
            check.insert(i);
        }
        else {
            for(long long j=i+1;;++j){
                if(check.find(j) == check.end()){
                    answer.push_back(j);
                    check.insert(j);
                    break;
                }
            }
        }
    }
    return answer;
}

// 제출 끝


int main(){

    long long k = 10;
    vector<long long> room_number;
    room_number = {1, 3, 4, 1, 3, 1};

    vector<long long> answer;
    answer = solution(k, room_number);

    for(auto i:answer){
        cout << i << ' ';
    }
    return 0;
}