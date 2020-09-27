#include <iostream>
using namespace std;

int sudoku[9][9];
int sudoku_c[9][9][10];

int main() {
    for(int i=0;i<9;++i) {
        for(int j=0, t;j<9;++j) {
            cin >> sudoku[i][j];
        }
    }
    for(int i=0;i<9;++i) {
        for(int j=0;j<9;++j) {
            if(sudoku[i][j] == 0) {
                for(int k=0;k<9;++k) {
                    sudoku_c[i][j][sudoku[i][k]] = 1;
                    sudoku_c[i][j][sudoku[k][j]] = 1;
                }
                for(int k=int(i/3)*3;k<(int(i/3)+1)*3;++k) {
                    for(int l=int(j/3)*3;l<(int(j/3)+1)*3;++l) {
                        sudoku_c[i][j][sudoku[k][l]] = 1;
                    }
                }
            }
        }
    }
}