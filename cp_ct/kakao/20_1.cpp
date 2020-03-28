#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> my_stack;
    my_stack.clear();
    int n = board.size();
    for(auto i:moves){
        for(int j=0;j<n;++j){
            if(board[j][i-1] != 0){
                if(!my_stack.empty() && my_stack.back() == board[j][i-1]){
                    answer += 2;
                    my_stack.pop_back();
                }
                else {
                    my_stack.push_back(board[j][i-1]);
                }
                board[j][i-1] = 0;
                break;
            }
        }
    }
    return answer;
}

int main(){
    vector<vector<int> > board;
    vector<int> moves {1,5,3,5,1,2,1,4};

    board.push_back({0, 0, 0, 0, 0});
    board.push_back({0, 0, 1, 0, 3});
    board.push_back({0, 2, 5, 0, 1});
    board.push_back({4, 2, 4, 4, 2});
    board.push_back({3, 5, 1, 3, 1});

    //cout << board.size();
    cout << solution(board, moves);
    return 0;
}