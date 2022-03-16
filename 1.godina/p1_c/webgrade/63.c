#include <stdio.h>

int main(){
int n;
scanf("%d",&n);
if (n<1){
 printf("-1\n");
 return 1;
}
double i;
double hs = 0;
for (i=1;i<=n;i++){
    hs+= 1/i;
}
printf("%.6lf\n",n/hs);
return 0;
}
