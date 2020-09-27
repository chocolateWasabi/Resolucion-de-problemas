#include <iostream>
using namespace std;

int n;
int paper[2500][2500];
int papertype[3];

void cutting(int lu_x, int lu_y, int rd_x, int rd_y){
    bool check = true;
    for(int i=lu_x;i<=rd_x && check;++i){
        for(int j=lu_y;j<=rd_y;++j){
            if(paper[i][j] != paper[lu_x][lu_y]){
                check = false;
                break;
            }
        }
    }
    if(check){
        papertype[paper[lu_x][lu_y]+1] ++;
        return;
    }

    int m3_1x, m3_1y, m3_2x, m3_2y;
    m3_1x = lu_x + (rd_x-lu_x+1)/3 - 1;
    m3_2x = lu_x + (rd_x-lu_x+1)/3*2 - 1;
    m3_1y = lu_y + (rd_y-lu_y+1)/3 - 1;
    m3_2y = lu_y + (rd_y-lu_y+1)/3*2 - 1;

    cutting(lu_x, lu_y, m3_1x, m3_1y);
    cutting(lu_x, m3_1y+1, m3_1x, m3_2y);
    cutting(lu_x, m3_2y+1, m3_1x, rd_y);
    cutting(m3_1x+1, lu_y, m3_2x, m3_1y);
    cutting(m3_1x+1, m3_1y+1, m3_2x, m3_2y);
    cutting(m3_1x+1, m3_2y+1, m3_2x, rd_y);
    cutting(m3_2x+1, lu_y, rd_x, m3_1y);
    cutting(m3_2x+1, m3_1y+1, rd_x, m3_2y);
    cutting(m3_2x+1, m3_2y+1, rd_x, rd_y);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1;i<=n;++i){  
        for(int j=1;j<=n;++j){
            cin >> paper[i][j];
        } 
    }

    cutting(1, 1, n, n);
    for(auto i:papertype){
        cout << i << '\n';
    }
    return 0;
}