#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class balance {
private:
    int trial;
    int n;
    int position[15], weight[15];
    void balance_main();
    double get_balance(int);
    double center_of_weight(int, int);
    double sum_of_weight(int, int);
public:
    balance(int trial){
        this->trial = trial;
        balance_main();
    }
};

void balance::balance_main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        cin >> position[i];
    }
    for(int i=1;i<=n;++i){
        cin >> weight[i];
    }

    cout << '#' << trial << ' ';
    for(int i=1;i<=n-1;++i){ // 각 위치에서의 균형점 찾기
        cout << get_balance(i) << ' ';
    }
    cout << '\n';
}

double balance::get_balance(int pos){
    double bal = double(position[pos]);
    double tmp, err, Fl, Fr;
    double minerr, mintmp;
    for(int i=1;i<=12;++i){
        minerr = 9999999999.9;
        for(int j=0;j<=9;++j){
            tmp = bal + pow(10.0, double(-i)) * j;
            Fl = Fr = 0.0;
            for(int k=1;k<=pos;++k){
                if(tmp != position[k]){
                    Fl += (double(weight[k]) / ((tmp - position[k]) * (tmp - position[k])));
                }
            }
            for(int k=pos+1;k<=n;++k){
                Fr += (double(weight[k]) / ((tmp - position[k]) * (tmp - position[k])));
            }
            err = Fl - Fr;
            cout << "tmp: " << tmp << " i:" << i << " j:" << j << " Fl:" << Fl << " Fr:" << Fr << " Err:" << err << '\n';
            if(abs(err) < minerr){
                minerr = abs(err);
                mintmp = tmp;
            }
        }
        bal = mintmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    streamsize prec = cout.precision();
    cout << fixed << setprecision(10);

    int T;
    cin >> T;
    for(int t=1;t<=T;++t){
        balance force(t);
    }

    cout << setprecision(prec);
    return 0;
}