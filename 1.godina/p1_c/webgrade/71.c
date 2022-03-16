#include <stdio.h>
#include <stdlib.h>

int main(){
int n,i,p = 1;
scanf("%d",&n);
if (n<=1){ printf("-1\n"); exit(EXIT_FAILURE);}
float broj1,broj2,broj;
scanf("%f",&broj1);
scanf("%f",&broj2);
for(i=3;i<=n;i++){
scanf("%f",&broj);
if((broj1/broj2)!=(broj2/broj)) p =0;
broj1 =broj2;
broj2=broj;
}
if(p==1)printf("1\n");
else printf("0\n");
exit(EXIT_SUCCESS);
}
