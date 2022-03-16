#include <stdio.h>
#include <stdlib.h>

int broj_cifara(int n){
    int b=0;
    while(n>0){
        b++;
        n/=10;
    }
    return b;
}

int main(){
int n,n1;

do{
    scanf("%d",&n);
    n1=abs(n);
    if(broj_cifara(n1)%2==1)
        printf("%d ",n);
}while(n!=0);
    

printf("\n");
exit(EXIT_SUCCESS);
}
