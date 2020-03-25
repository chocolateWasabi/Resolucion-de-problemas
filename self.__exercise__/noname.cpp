#include <cstdio> // skku mcsl lab intern tryout
int main(){
    auto func = [](int n){return (n & -n) == n ? 1 : 0;};
    for(int n;~scanf("%d", &n);printf("%d\n",func(n)?1:0));
    return 0;
}