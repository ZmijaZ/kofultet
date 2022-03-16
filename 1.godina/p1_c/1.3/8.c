#include <stdio.h>

int main (){

int n;
int n1;


int s = 0;
scanf("%d",&n);
if (n<0){
    printf("neispravan unos\n");
    return 1;
    }
n1 = n;
while(n>0){
    s = s+n%10;
    n=n/10;
    }
if(n1%s==0){

  printf("Broj: %d je deljiv sumom: %d\n",n1,s);  
    return 0;
}
}
