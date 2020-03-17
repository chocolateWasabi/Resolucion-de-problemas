// BOJ ID 1992 Quad Tree
#include <iostream>
#include <string>
using namespace std;

int n;
char image[70][70];

void quadtree(int lu_x, int lu_y, int rd_x, int rd_y, string& compressed){
    int md_x = (lu_x + rd_x) / 2;
    int md_y = (lu_y + rd_y) / 2;
    bool flag1, flag2, flag3, flag4;
    flag1 = flag2 = flag3 = flag4 = true;
    // area 1
    for(int i=lu_x;i<=md_x && flag1;++i){
        for(int j=lu_y;j<=md_y;++j){
            if(image[i][j] != image[lu_x][lu_y]){
                flag1 = false;
                break;
            }
        }
    }
    // area 2
    for(int i=lu_x;i<=md_x && flag2;++i){
        for(int j=md_y+1;j<=rd_y;++j){
            if(image[i][j] != image[lu_x][md_y+1]){
                flag2 = false;
                break;
            }
        }
    }
    // area 3
    for(int i=md_x+1;i<=rd_x && flag3;++i){
        for(int j=lu_y;j<=md_y;++j){
            if(image[i][j] != image[md_x+1][lu_y]){
                flag3 = false;
                break;
            }
        }
    }
    // area 4
    for(int i=md_x+1;i<=rd_x && flag4;++i){
        for(int j=md_y+1;j<=rd_y;++j){
            if(image[i][j] != image[md_x+1][md_y+1]){
                flag4 = false;
                break;
            }
        }
    }

    // 2: area 1
    if(!flag1){
        compressed += '(';
        quadtree(lu_x, lu_y, md_x, md_y, compressed);
        compressed += ')';
    }
    else {
        compressed += image[lu_x][lu_y];
    }

    // 2: area 2
    if(!flag2){
        compressed += '(';
        quadtree(lu_x, md_y+1, md_x, rd_y, compressed);
        compressed += ')';
    }
    else {
        compressed += image[lu_x][md_y+1];
    }

    // 2: area 3
    if(!flag3){
        compressed += '(';
        quadtree(md_x+1, lu_y, rd_x, md_y, compressed);
        compressed += ')';
    }
    else {
        compressed += image[md_x+1][lu_y];
    }

    // 2: area 4
    if(!flag4){
        compressed += '(';
        quadtree(md_x+1, md_y+1, rd_x, rd_y, compressed);
        compressed += ')';
    }
    else {
        compressed += image[md_x+1][md_y+1];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool finish = true;
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> image[i];
        for(int j=0;j<n && finish;++j){
            if(image[i][j] != image[0][0]){
                finish = false;
                break;
            }
        }
    } // (0(0011)(0(0111)01)1)

    if(!finish){
        string compressed = "";
        quadtree(0, 0, n-1, n-1, compressed);
        cout << '(' << compressed << ')';
    }
    else {
        cout << image[0][0];
    }
    return 0;
}