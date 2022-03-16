#include <stdio.h>
#include <stdlib.h>

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n,i;
int a,b,max,maxs;
scanf("%d",&n);
        if(n<0) greska();
scanf("%d",&a);
a=abs(a);
        if(a>9999 || a<1000) greska();
maxs=(a%1000)/100; max=a;

for (i=2;i<=n;i++){
scanf("%d",&b);
b=abs(b);
        if(b>9999 || b<1000) greska();
if (((b%1000)/100)>=maxs)
{max=b;maxs=(b%1000)/100;}
}

int zbir=0;
while(max>0){zbir+=max%10;max/=10;}
printf("%d\n",zbir);
}
