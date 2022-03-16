#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
int n,i,broj,sum=0;
int a[N];
int b[N];
scanf("%d",&n);
if(n<1||n>N){
printf("-1\n");
exit(EXIT_FAILURE);
}
for (i=0;i<n;i++){
scanf("%d",&broj);
sum+=broj;
b[i]=sum;
}

for(i=0;i<n;i++){
printf("%d ",b[i]);
}
printf("\n");
}
