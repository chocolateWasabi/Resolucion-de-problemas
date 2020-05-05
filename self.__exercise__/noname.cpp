#include <cstdio>
#include <cstdlib>

int main(){

    int *a = (int*) malloc(sizeof(int) * 1);
    int *b = (int*) malloc(sizeof(int) * 1);

    *a = 20;
    *b = 30;
    
    printf("%d %d\n", *a, *b);

    *a ^= *b;
    *b ^= *a;
    *a ^= *b;

    printf("%d %d\n", *a, *b);
    free(a); free(b);
    return 0;
}