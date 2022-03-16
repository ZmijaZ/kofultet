#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int n,i,sum=1;
scanf("%d",&n);
if(n<1||n>100){
printf("-1\n");
exit(EXIT_FAILURE);
}
for(i=0;i<n;i++){
if(i%2==0){
printf("\t~%d~\t\n",sum);
}
if(i%2==1){
printf("\t~0%d~\t\n",sum);
sum+=(int)pow(10,i+1);
}
}
exit(EXIT_SUCCESS);
}
