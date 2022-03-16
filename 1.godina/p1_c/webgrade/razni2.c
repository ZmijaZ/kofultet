#include <stdio.h>
#include <stdlib.h>


unsigned suma_kubova_cifara(unsigned x){
    int zbir=0,kub;
    while(x>0){
    kub=1;
        for(int i=1;i<=3;i++){
        kub*=x%10;
        }
    zbir+=kub;
    x/=10;
    }
    return zbir;
}


int main(){

unsigned n;
scanf("%u",&n);
printf("%u\n",suma_kubova_cifara(n));

exit(EXIT_SUCCESS);
}
