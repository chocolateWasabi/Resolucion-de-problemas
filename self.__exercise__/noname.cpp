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
    double dv1 = center_of_weight(1, pos);
    double dv2 = center_of_weight(pos+1, n);
    double w1 = sum_of_weight(1, pos);
    double w2 = sum_of_weight(pos+1, n);

    cout << dv1 <<' ' << dv2 << ' ' << w1 << ' ' << w2 << '\n';


    double sol1, sol2;
    
    if(w1 != w2){
        sol1 = ((dv2*w1-dv1*w2) + sqrt((dv2*w1-dv1*w2)*(dv2*w1-dv1*w2)-(w1-w2)*(w1*dv2*dv2-w2*dv1*dv1)))/(w1-w2);
        sol2 = ((dv2*w1-dv1*w2) - sqrt((dv2*w1-dv1*w2)*(dv2*w1-dv1*w2)-(w1-w2)*(w1*dv2*dv2-w2*dv1*dv1)))/(w1-w2);
    }
    else {
        sol1 = sol2 = (dv1 + dv2) / 2.0;
    }

    //cout << sol1 << ' ' << sol2 << '\n';
    if(sol1 > double(position[pos]) && sol1 < double(position[pos+1])){
        return sol1;
    }
    else {
        return sol2;
    }
}

double balance::center_of_weight(int s, int e){
    double a, b; // 질량 중심
    a = b = 0.0;
    for(int i=s;i<=e;++i){
        a += double(weight[i]) * position[i];
        b += double(weight[i]);
    }
    return a / b;
}

double balance::sum_of_weight(int s, int e){
    double a = 0.0;
    for(int i=s;i<=e;++i){
        a += double(weight[i]);
    }
    return a;
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