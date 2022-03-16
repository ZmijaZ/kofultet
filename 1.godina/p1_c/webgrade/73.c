#include <stdio.h>
#include <stdlib.h>

int main(){
int i,n;
int b1=0,b2=1;
int c =0;
scanf("%d",&n);
if(n<1){
printf("-1\n");
exit(EXIT_FAILURE);}
if (n==1){printf("%d\n",b1);}
    else if(n==2){printf("%d %d \n",b1, b2);}
        else 
    {printf("%d %d ",b1,b2);}  
for(i=3;i<=n;i++){
    c=b1+b2;
    printf("%d ",c);
b1=b2;
b2=c;
}
printf("\n");}
