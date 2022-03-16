#include <stdio.h>
#include <math.h>

int main(){
int m,n,i;
int rez=1;
scanf ("%d %d",&m, &n);
if (n<0){
printf("-1\n");
return 1;}

for (i=1;i<=n;i++){
    rez+=pow(m,i);
}
printf("%d\n",rez);
return 0;
}
