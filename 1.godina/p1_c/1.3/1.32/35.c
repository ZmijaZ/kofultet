#include <stdio.h>
#include <math.h>

int main(){

int n;
scanf("%d",&n);
if (n<1){
    printf("Pogresan unos\n");
    return 0;
}
int k;
int s=0;
for(k=1;k<=n;k++){
    s+= pow(k,3);
    printf("[k=%d] Suma kubova: %d\n",k,s);
}
}
