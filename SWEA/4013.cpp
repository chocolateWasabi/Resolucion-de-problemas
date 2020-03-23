// SWEA 4013 특이한 자석 - 시뮬레이션
#include <iostream>
using namespace std;

void rotate_mag(int *arr, int cw){
    if(cw == 1){
        int tmp = arr[7];
        for(int i=7;i>0;--i){
            arr[i] = arr[i-1];
        }
        arr[0] = tmp;
    }
    else { // cw == -1
        int tmp = arr[0];
        for(int i=0;i<7;++i){
            arr[i] = arr[i+1];
        }
        arr[7] = tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, K;
    int magnetic[4][8], mag_n, cw;
    cin >> T;
    for(int t=1;t<=T;++t){
        cin >> K;
        for(int i=0;i<4;++i){
            for(int j=0;j<8;++j){
                cin >> magnetic[i][j];
            }
        }
        for(int i=0;i<K;++i){
            cin >> mag_n >> cw;
            mag_n --;
            switch(mag_n){
            case 0:
                if(magnetic[0][2] != magnetic[1][6]){ // 1, 2번 자석
                    if(magnetic[1][2] != magnetic[2][6]){ // 1, 2, 3번 자석
                        if(magnetic[2][2] != magnetic[3][6]){ // 1, 2, 3, 4번 자석
                            rotate_mag(magnetic[3], -cw);
                        }
                        rotate_mag(magnetic[2], cw);
                    }
                    rotate_mag(magnetic[1], -cw);
                }
                rotate_mag(magnetic[0], cw);
            break;
            case 1:
                if(magnetic[1][6] != magnetic[0][2]){
                    rotate_mag(magnetic[0], -cw);
                }
                if(magnetic[1][2] != magnetic[2][6]){
                    if(magnetic[2][2] != magnetic[3][6]){
                        rotate_mag(magnetic[3], cw);
                    }
                    rotate_mag(magnetic[2], -cw);
                }
                rotate_mag(magnetic[1], cw);
            break;
            case 2:
                if(magnetic[3][6] != magnetic[2][2]){
                    rotate_mag(magnetic[3], -cw);
                }
                if(magnetic[1][2] != magnetic[2][6]){
                    if(magnetic[0][2] != magnetic[1][6]){
                        rotate_mag(magnetic[0], cw);
                    }
                    rotate_mag(magnetic[1], -cw);
                }
                rotate_mag(magnetic[2], cw);
            break;
            case 3:
                if(magnetic[3][6] != magnetic[2][2]){
                    if(magnetic[2][6] != magnetic[1][2]){
                        if(magnetic[1][6] != magnetic[0][2]){
                            rotate_mag(magnetic[0], -cw);
                        }
                        rotate_mag(magnetic[1], cw);
                    }
                    rotate_mag(magnetic[2], -cw);
                }
                rotate_mag(magnetic[3], cw);
            break;
            }
        }
        cout << '#' << t << ' ' << magnetic[0][0]*1 + magnetic[1][0]*2 + magnetic[2][0]*4 + magnetic[3][0]*8 << '\n';
    }

    return 0;
}