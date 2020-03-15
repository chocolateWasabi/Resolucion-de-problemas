#include <iostream>
#include <cstring>
using namespace std;

int clock[16];
int switches[10][5] = {
    {0, 1, 2}, // 0
    {3, 7, 9, 11}, // 1
    {4, 10, 14, 15}, // 2
    {0, 4, 5, 6, 7}, // 3
    {6, 7, 8, 10, 12}, // 4
    {0, 2, 14, 15}, // 5
    {3, 14, 15}, // 6
    {4, 5, 7, 14, 15}, // 7
    {1, 2, 3, 4, 5}, // 8
    {3, 4, 5, 9, 13}  // 9
};

int switch_clock[][] = {
    {0, 3, 5}, // 0
    {0, 8}, // 1
    {0, 5, 8}, // 2
    {1, 6, 8, 9}, // 3
    {2, 3, 7, 8, 9}, // 4
    {3, 7, 8, 9}, // 5
    {3, 4}, // 6
    {1, 3, 4, 7}, // 7
    {4}, // 8
    {1, 9}, // 9
    {2, 4}, // 10
    {1}, // 11
    {4}, // 12
    {9}, // 13
    {2, 5, 6, 7}, // 14
    {2, 5, 6, 7}  // 15
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;

    cin >> C;
    for(int c=1;c<=C;++c){
        memset(clock, 0, sizeof(clock));
        for(int i=0;i<16;++i){
            cin >> clock[i];
        }


    }
    return 0;
}