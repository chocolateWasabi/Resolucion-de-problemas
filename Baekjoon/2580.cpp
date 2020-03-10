// BOJ ID 2580 (SUDOKU)
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
//#include <set>
using namespace std;

int table[9][9];
vector<vector<int>> candidate(9);
vector<vector<int>> omit_coord(9);
//set<int> check_y[9], check_block[9];

int check_y[9][10], check_block[9][10];
// 9개의 열, 9개의 블록, 각 열과 블록마다 0부터 9까지의 수

inline void print_table(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

void sudoku(int row){
    if(row == 9){
        print_table();
        exit(0);
    }

    int size = candidate[row].size();
    
    vector<int> tmp;
    tmp.clear();
    for(int i=0;i<size;++i){ tmp.push_back(i); }

    int tti;
    bool test;
    do{
        tti = 0;
        test = true;

        for(auto i:omit_coord[row]){
            table[row][i] = candidate[row][tmp[tti]];
            tti ++;

            // verify procedure

            if(check_y[i][table[row][i]] != 0){
                test = false;
                break;
            }

            if(check_block[3*(row/3)+(i/3)][table[row][i]] != 0){
                test = false;
                break;
            }
        }
        
        if(test){
            for(auto i:omit_coord[row]){
                check_y[i][table[row][i]] = 1;
                check_block[3*(row/3)+(i/3)][table[row][i]] = 1;
            }

            sudoku(row+1);

            // 안 되는 경우 복구1
            for(auto i:omit_coord[row]){
                check_y[i][table[row][i]] = 0;
                check_block[3*(row/3)+(i/3)][table[row][i]] = 0;
            }
        }

        // 안 되는 경우 복구2
        for(auto i:omit_coord[row]){
            table[row][i] = 0;
        }
        
    }while(next_permutation(tmp.begin(), tmp.end()));
}

int main(){
    int check[10];
    for(int i=0;i<9;++i){
        memset(check, 0, sizeof(check));
        for(int j=0;j<9;++j){
            scanf("%d", &table[i][j]);
            if(table[i][j] != 0){ // 열, 구역별 체크
                check_y[j][table[i][j]] = 1;
                check_block[3*(i/3)+(j/3)][table[i][j]] = 1;
            }
            check[table[i][j]] = 1;
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

    sudoku(0);
    return 0;
}