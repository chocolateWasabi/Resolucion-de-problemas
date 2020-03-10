// BOJ ID 2580 (SUDOKU)
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool verify(int (*table)[9]){
    int sum1, sum2;
    int blocksum[9];
    memset(blocksum, 0, sizeof(blocksum));
    //cout << "verifying";
    for(int i=0;i<9;++i){
        sum1 = sum2 = 0;
        for(int j=0;j<9;++j){
            sum1 += table[i][j];
            sum2 += table[j][i];

            blocksum[3*(i/3)+j/3] += table[i][j];
        }
        if(sum1 != 45) return false;
        if(sum2 != 45) return false;
    }
    for(int i=0;i<9;++i){
        if(blocksum[i] != 45) return false;
    }
    return true;
}

int factorial(int n){
    int result = 1;
    for(;n>0;--n){
        result *= n;
    }
    return result;
}

void sudoku(int row, int (*table)[9], vector<vector<int>>& candidate, vector<vector<int>>& omit_coord, bool& finish){
    if(row == 9){
        finish = verify(table);
        if(finish){
            for(int i=0;i<9;++i){
                for(int j=0;j<9;++j){
                    cout << table[i][j] << ' ';
                }
                cout << '\n';
            }
        }
        return;
    }
    if(!finish){
        int size = omit_coord[row].size();
        int fact = factorial(size);
        int tmp[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        for(;fact>0;--fact){
            int tti = 0;
            for(auto i:omit_coord[row]){
                table[row][i] = candidate[row][tmp[tti]];
                tti ++;
            }

            sudoku(row+1, table, candidate, omit_coord, finish);
            if(finish){
                break;
            }
            next_permutation(tmp, tmp+size);
        }


    }
}

int main(){
    int check[10], table[9][9];
    vector<vector<int>> candidate(9);
    vector<vector<int>> omit_coord(9);
    for(int i=0;i<9;++i){
        memset(check, 0, sizeof(check));
        for(int j=0;j<9;++j){
            cin >> table[i][j];
            check[table[i][j]] ++;
            if(table[i][j] == 0){
                omit_coord[i].push_back(j);
            }
        }
        for(int j=1;j<10;++j){
            if(check[j] == 0){
                candidate[i].push_back(j);
            }
        }
    }

    bool finish = false;
    sudoku(0, table, candidate, omit_coord, finish);
    return 0;
}