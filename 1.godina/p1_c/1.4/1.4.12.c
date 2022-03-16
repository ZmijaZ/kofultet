#include <stdio.h>
#include <stdlib.h>
int p(int n){
    char p =1;
    n = abs(n);
    while (n>0){
    if (n%2==1){
        p = 0;}
    n = n/10;
    }
    return p;
}
int i(int n){
    int kec,dva,tmp;
    char i =1;
    n = abs(n);
    kec = n%10;
    n = n/10;
    while (n>0){
       dva = n%10;
    if (kec%2== dva%2){
        i = 0;}
        kec =dva;
       n = n/10;
       
    }
    return i;
}
    
    
    
int main (){
int broj;
scanf("%d",&broj);
printf("%d\n",i(broj));
}

