#include <stdio.h>

float as(int n){
    float zbir,rez ,brojac=0;

    while (n>0){
    zbir = zbir+n%10;
    brojac++;
    n = n/10;
    }
    rez = zbir/brojac;
    return rez;
}
    
int main (){
int n;
scanf("%d",&n);
printf("%.3f\n", as(n));
}
