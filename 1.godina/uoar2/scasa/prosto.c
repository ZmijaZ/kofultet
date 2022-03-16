#include <stdio.h>

int prost(int n);

int main(){
    int n;
    scanf("%d", &n);
    if(prost(n))
        printf("Prost je\n");
    else
        printf("Nije prost\n");
return 1;
}
