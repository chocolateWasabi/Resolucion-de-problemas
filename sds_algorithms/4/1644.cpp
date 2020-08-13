#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;
void makePrimes() {
    bool isPrime;
    primes.clear();
    for(int i=2;i<=2000100;++i) {
        isPrime = true;
        for(int j=2;j*j<=i;++j) {
            if(!(i % j)) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            primes.push_back(i);
        }
    }
}

int main() {
    primes.reserve(150000);
    makePrimes();

    return 0;
}