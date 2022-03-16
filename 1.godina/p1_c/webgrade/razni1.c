#include <stdio.h>
#include <stdlib.h>

unsigned obrni(unsigned x){
    int x1=0;
    while(x>0){
        x1=x1*10+x%10;
        x/=10;
    }
    return x1;
}

int main(){
unsigned n;
scanf("%u",&n);
printf("%u\n",obrni(n));


exit(EXIT_SUCCESS);
}
