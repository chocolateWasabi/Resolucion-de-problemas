#include <iostream>
using namespace std;

int main(){
	int n;
	
	cin >> n;
	
	// 1, 7, 4, 5, 9, 8 중 숫자가 큰 4, 5, 9, 8 을 사용하는 것보다
	// 1, 7 만을 이용해 자리수를 최대한 늘려나가는 게 큰 값.
	// 최대 1 500개라서 long long 의 범위를 벗어남. (산술적 처리 불가능)
	
	if(n & 1){
		cout << 7;
		n -= 3;
	}
	
	for(;n > 0;n -= 2){
		cout << 1;
	}
	
	return 0;
}