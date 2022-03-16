#include <stdio.h>
#include <stdlib.h>

void printbits(int x){
    unsigned maska = 1 << (8*sizeof(int)-1);
    while(maska){
        printf("%c", maska&x ? '1' : '0');
        maska >>=1;
    }
    printf("\n");
}

unsigned invertovanje(unsigned x, unsigned k, unsigned p){
    unsigned maska1 = 1;
    unsigned maskak = 0;
    unsigned maskap = 0;
    
    for(unsigned i = 0; i<k; i++, maska1<<=1)
        maskak = maskak | maska1;
    
    maska1 = 1;
    
    for(unsigned i = 0; i<p; i++, maska1<<=1)
        maskap = maskap | maska1;
    
    maskap<<=(8*sizeof(int)-p);
    
    maskap = maskap | maskak;
    
    return maskap^x;
}

int main(){
    unsigned x, k, p;
    scanf("%u%u%u", &x, &k, &p);

    x = invertovanje(x, k, p);
    
    printf("%u\n", x);
exit(EXIT_SUCCESS);
}
