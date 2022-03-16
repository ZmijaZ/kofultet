#include <stdio.h>
#include <stdlib.h>
int main(){
int n,i;
scanf("%d",&n);
if (n==0){
printf("Nije unet ni jedan broj");
return 1;
}
int proizvod=1;
for(i=1;i<=n;i++){
    int broj;
    scanf("%d",&broj);
    if(broj>0){
    proizvod*=broj;
    }else if(broj ==0){
    break;
    }
}
printf("Proizvod je: %d\n",proizvod);
return 0;
}    
