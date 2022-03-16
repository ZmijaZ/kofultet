#include <stdio.h>
#include <stdlib.h>
int main (){
float x;
float x1 = 1.0;
int n;
scanf("%f%d",&x,&n);
int i;
for(i = 1;i<=abs(n);i++){
    x1*=x;
}
if(n<0){
x1 = 1/x1;
}
printf("%.4f^%d: %.4f",x,n,x1);
}
