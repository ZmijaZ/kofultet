#include <stdio.h>

int main(){

int n,i,j,k;
scanf("%d",&n);
for (i=0;i<=n-1;i++){
   for (j=n;j>0;j--)
   for (k=1;k<=n;k++)
       if(k == j){
           printf("*");
    }else{printf(" ");}
}
 printf("\n");
}
