#include <stdio.h>
#include <stdlib.h>

void greska(void){
printf("-1\n");
exit(EXIT_FAILURE);
}

int provera (int n){
    int p=0;int h,s,d,j;
    h=n/1000;s=(n%1000)/100;d=(n%100)/10;j=n%10;
    if(h<s && s<d && d<j)p=j;
    return p;
}

int main(){
int n,broj,i,x,res=0,b1=0;
scanf("%d",&n);
if (n<1)greska();
    for(i=1;i<=n;i++){
    scanf("%d",&broj);
    broj = abs(broj);
        if(broj<1000||broj>9999)greska();
    x=provera(broj);
    if(x>0) res=x; b1++;
    if(b1>0 && x>0)continue;    
    
    }
printf("%d\n",res);
exit(EXIT_SUCCESS);
}
