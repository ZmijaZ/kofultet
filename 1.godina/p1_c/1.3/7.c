#include <stdio.h>

int main (){

int n;
int n1 = 0;
scanf("%d",&n);
if (n<0){
    printf("neispravan unos\n");
    return 1;
    }

while(n>0){
    n1 = n1*10+n%10;
    n=n/10;
    }
  printf("Obrnuti poredak: %d\n",n1);  
}
