#include <stdio.h>
#include <stdlib.h>

int obrni (int n){
    int zbir=0;
    while(n>0){
        zbir=zbir*10 + n%10;
        n/=10;
    }
    return zbir;
}


int main (){
int n; int zbir=0;
scanf("%d",&n);
int n1 = abs(n);
while(n1>0){
if(n1%2==1)
zbir=zbir*10+n1%10;
n1/=10;
}
zbir= obrni(zbir);
if(n<0)zbir=-zbir;

printf("%d\n",zbir);
exit(EXIT_SUCCESS);
}
