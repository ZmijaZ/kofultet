#include <stdio.h>

void kolicnik (int a, int b, int*k, int*d, int*e, int *n);

int main(){
    int a, b, k, d, e, n;
    scanf("%d%d", &a, &b);
    kolicnik(a, b, &k, &d, &e, &n);
    printf("%d %d %d %d\n", k, d, e, n);
}
