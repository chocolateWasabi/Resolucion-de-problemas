// programmers 첫 문제! 코딩테스트 연습 -> 완전탐색 -> 모의고사(42840)
// 2020-03-06
// 여기 사이트는 특이한 점이 main 함수가 따로 없다. 삼성 B형 예시 문제처럼 동작에 필요한 함수를 작성하는 형태인듯.
// 시간 잡고 푸는 레벨 테스트가 있어서 한 번씩 시간 내서 도전해봐야겠다.
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> first{1, 2, 3, 4, 5}, second{2, 1, 2, 3, 2, 4, 2, 5}, third{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int fn, sn, tn;
    fn = first.size(), sn = second.size(), tn = third.size();
    
    int fc, sc, tc;
    fc = sc = tc = 0;
    
    vector<int>::iterator fi, si, ti;
    fi = first.begin(), si = second.begin(), ti = third.begin();
    
    for(auto i:answers){
        // 각 수포자의 찍는 패턴에 대한 iterator 처리
        if(fi == first.end()){
            fi = first.begin();
        }
        if(si == second.end()){
            si = second.begin();
        }
        if(ti == third.end()){
            ti = third.begin();
        }
        
        // 정답을 맞추었으면 각 수포자의 count를 올려 준다.
        if(i == *fi){
            fc ++;
        }
        if(i == *si){
            sc ++;
        }
        if(i == *ti){
            tc ++;
        }
        fi ++, si ++, ti ++;
    }
    
    // 각 case별로 분기하여 answer vector에 결과 값 삽입.
    if(fc > sc){
        if(fc > tc){
            answer.push_back(1);
        }
        else if(fc == tc){
            answer.push_back(1);
            answer.push_back(3);
        }
        else { // sc < fc < tc
            answer.push_back(3);
        }
    }
    else if(fc == sc){
        if(fc > tc){
            answer.push_back(1);
            answer.push_back(2);
        }
        else if(fc == tc){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else { // fc == sc < tc
            answer.push_back(3);
        }
    }
    else { // fc < sc
        if(fc > tc){ // tc < fc < sc
            answer.push_back(2);
        }
        else if(fc == tc){ // fc == tc < sc
            answer.push_back(2);
        }
        else { // fc < tc, fc < sc, 즉 sc와 tc의 우열 가려야 한다.
            if(sc > tc){ // sc > tc > fc
                answer.push_back(2);
            }
            else if(sc == tc){
                answer.push_back(2);
                answer.push_back(3);
            }
            else { // fc < sc < tc
                answer.push_back(3);
            }
        }
    }
    return answer;
}