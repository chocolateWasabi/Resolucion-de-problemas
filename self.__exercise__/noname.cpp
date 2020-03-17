#include <iostream>
using namespace std;

#define max 5
int main(){

    int a, b, n;
    int count = 0;
    for(a=-max;a<=max;++a){
        for(b=-max;b<=max;++b){
            for(n=1;n<=max;++n){/*
                if(a % n - b % n == (a - b) % n){
                   // cout << a % n << ' ' << b % n << ' ' << (a - b) % n << endl;
                    count ++;
                }
                else {
                    cout << a << ' ' << b << ' ' << a % n << ' ' << b % n << ' ' << n << endl;
                }*/

                if(a % n >= b % n){
                    if(a % n - b % n != (a - b) % n){
                        cout << a << ' ' << b << ' ' << n << " | " << a % n << ' ' << b % n << ' ' << (a - b) % n << endl;
                    }
                }
            }
        }
    }
    cout << count;
    return 0;
}