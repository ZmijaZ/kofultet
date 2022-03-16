#include <stdio.h>
#include <stdlib.h>

void greska (void){
printf("-1\n");
exit(EXIT_FAILURE);
}

int main(){
int n,i,broj,p=1,a;
int mind,min;
scanf("%d",&n);
scanf("%d",&a);a=abs(a);if(a>99999||a<10000)greska();
min =a;
mind = (a%100)/10;
if(n<1)greska();
for (i=2;i<=n;i++){
scanf("%d",&broj);
broj=abs(broj);
    if(broj>99999 || broj<10000){greska();}
if ((broj%100)/10<mind){mind=((broj%100)/10);min=broj;
}
}
while(min>0){
    p*=min%10;
    min/=10;
}
printf("%d\n",p); exit(EXIT_SUCCESS);
}
