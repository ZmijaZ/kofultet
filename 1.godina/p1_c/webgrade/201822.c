#include <stdio.h>
#include <stdlib.h>

void greska(void){
printf("-1\n");
exit(EXIT_FAILURE);
}

int provera (int n){
    int s,d,j,p=-2;
    s= n/100; d= (n%100)/10; j= n%10;
    if (s>d && d>j) p=j;
    return p;
}

int main(){
int n,i,x=0;  int broj,broj1,b=0;
scanf("%d",&n);     if(n<1)greska();

for(i=1;i<=n;i++){
    scanf("%d",&broj);
    broj1=abs(broj); if(broj1>999||broj1<100)greska();
    if (provera(broj1)>-2){b++; x=provera(broj1);}
}
if(b==0)x=broj;
printf("%d\n",x);
exit(EXIT_SUCCESS);
}
