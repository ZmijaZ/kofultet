#include <stdio.h>

int main(){
int n,i;
if (n<0){
printf("Pogresan unos\n");
return 0;
}
scanf("%d",&n);
int f =1;
for(i=1;i<=n;i++){
    f= f*i;
}
printf("Faktorijel je: %d\n",f);
return 1;
}
