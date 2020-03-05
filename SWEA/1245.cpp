#include <iostream>
#include <iomanip>
#include <cmath>
#include <utility>
using namespace std;

class balance {
private:
    int trial;
    int n;
    int position[15], weight[15];
    void balance_main();
    double get_balance(int);
    pair<double, double> get_error(int, double);
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
    double tmp, err;
    pair<double, double> F;

    double Dl, Dr;
    Dl = position[pos];
    Dr = position[pos+1];
    for(int i=1;i<=50;++i){
        tmp = (Dl + Dr) / 2;
        //tmp = bal + pow(10.0, double(-i)) * j;
        //tmp를 이분 탐색으로 구해야 한다.
        F = get_error(pos, tmp);
        //cout << "tmp: " << tmp << " Fl:" << F.first << " Fr:" << F.second << " Err:" << err << '\n';
        if(F.first < F.second){
            Dr = tmp;
        }
        else{
            Dl = tmp;
        }
    }
    return (Dl + Dr) / 2;
}

pair<double, double> balance::get_error(int pos, double tmp){
    double Fl, Fr;
    Fl = Fr = 0.0;
    for(int k=1;k<=pos;++k){
        if(tmp != position[k]){
            Fl += (double(weight[k]) / ((tmp - position[k]) * (tmp - position[k])));
        }
    }
    for(int k=pos+1;k<=n;++k){
        Fr += (double(weight[k]) / ((tmp - position[k]) * (tmp - position[k])));
    }
    return {Fl, Fr};
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