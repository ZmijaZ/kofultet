#include <stdio.h>
#include <stdlib.h>
int main(){
int n,i;
scanf("%d",&n);
int zbir=0;
for(i=1;i<=n;i++){
    int broj;
    scanf("%d",&broj);
    if(broj<0&&abs(broj)%2==1){
    zbir+=broj;
   
}


}
printf("Zbir je: %d\n",zbir);
}
