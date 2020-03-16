#include <iostream>
using namespace std;

int n;
int paper[150][150];

void make_paper(int lu_x, int lu_y, int rd_x, int rd_y, int& blue, int crit){

    if(lu_x == rd_x){ // 기저 사례
        if(paper[lu_x][lu_y] == crit){
            blue += 1;
        }
        return;
    }

    bool check1, check2, check3, check4;
    check1 = check2 = check3 = check4 = true;
    // area 1
    int md_x = (lu_x+rd_x)/2;
    int md_y = (lu_y+rd_y)/2;
    for(int i=lu_x;i<=md_x && check1;++i){
        for(int j=lu_y;j<=md_y;++j){
            if(paper[i][j] != crit){
                check1 = false;
                break;
            }
        }
    }
    // area 2
    for(int i=md_x+1;i<=rd_x && check2;++i){
        for(int j=lu_y;j<=md_y;++j){
            if(paper[i][j] != crit){
                check2 = false;
                break;
            }
        }
    }
    // area 3
    for(int i=lu_x;i<=md_x && check3;++i){
        for(int j=md_y+1;j<=rd_y;++j){
            if(paper[i][j] != crit){
                check3 = false;
                break;
            }
        }
    }
    // area 4
    for(int i=md_x+1;i<=rd_x && check4;++i){
        for(int j=md_y+1;j<=rd_y;++j){
            if(paper[i][j] != crit){
                check4 = false;
                break;
            }
        }
    }

    //int plus = (rd_x - lu_x + 1) * (rd_y - lu_y + 1);
    //plus /= 4;
    if(!check1){
        make_paper(lu_x, lu_y, md_x, md_y, blue, crit);
    }
    else{
        blue ++;
    }

    if(!check2){
        make_paper(md_x+1, lu_y, rd_x, md_y, blue, crit);
    }
    else {
        blue ++;
    }

    if(!check3){
        make_paper(lu_x, md_y+1, md_x, rd_y, blue, crit);
    }
    else{
        blue ++;
    }

    if(!check4){
        make_paper(md_x+1, md_y+1, rd_x, rd_y, blue, crit);
    }
    else {
        blue ++;
    }

    if(check1 && check2 && check3 && check4){
        blue -= 3;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> paper[i][j];
        }
    }

    int blue = 0;
    make_paper(0, 0, n-1, n-1, blue, 1);

    int white = 0;
    make_paper(0, 0, n-1, n-1, white, 0);

    cout << white << '\n' << blue;
    return 0;
}