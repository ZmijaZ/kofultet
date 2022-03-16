#include <stdio.h>

int main (){
 int n, i;
 long int n1 =1;
 scanf("%d",&n);
 
if(n<1){
    printf("-1\n");
    return 1;
}
if (n%2==0){
    for(i=2;i<=n;i+=2){
        n1*=i;}
}
if (n%2==1){
    for(i=1;i<=n;i+=2){
        n1*=i;}
}
printf("%ld\n",n1);
return 0;
}
