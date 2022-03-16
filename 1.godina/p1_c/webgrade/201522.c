#include <stdio.h>
#include <stdlib.h>
int main(){
int n,p=1,n1;
scanf("%d",&n);
n1=n;
while(n1>0){
if(n1%2==0){
p*=n1%10;
}
n1/=10;
}
printf("%d\n",n*p);
}
