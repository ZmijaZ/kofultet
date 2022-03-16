#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int obrni(int n){
     int b=0;
     while(n>0){
         b=b*10+n%10;n/=10;
}return b;
}


int main(){
int n,n1,zbir=0;
scanf("%d",&n);
n1 = abs(n);



while(n1>0){
if(n1%2==1)
    zbir=zbir*10+n1%10;
n1/=10;
}zbir = obrni(zbir);
if(n<0)zbir=-zbir;
printf("%d\n",zbir);
}
