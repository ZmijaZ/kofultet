#include <stdio.h>
#include <stdlib.h>
int zbir(int x){
x=abs(x);
int c,zbir=0;
c=x%10;
while(x>10){;
x/=10;
}
zbir=x+c; return zbir;
}

int main(){
int n;
scanf("%d",&n);
printf("%d\n",zbir(n));
exit(EXIT_SUCCESS);
}
