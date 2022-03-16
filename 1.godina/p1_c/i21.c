#include <stdio.h>
#include <stdlib.h>

int obrni(int n){
    int zbir=0;
    while(n>0){
    zbir = zbir*10+n%10;
    n/=10;
    }
    return zbir;
}

int main(){
int n; float as=0; int b=0; int zbir=0;
scanf("%d",&n);
int n1=abs(n);
while(n1>0){
as+=n1%10;
b++;
n1/=10;
}
as=as/b;
n1 = abs(n);
while(n1>0){
    if(n1%10<as)
    zbir= zbir*10+n1%10;
    n1/=10;
}
zbir= obrni(zbir);
if(n<0)zbir=-zbir;

printf("%d\n",zbir);
exit(EXIT_SUCCESS);
}
