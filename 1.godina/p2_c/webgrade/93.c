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

unsigned invertujk(unsigned x, unsigned k){
    unsigned maska1 = 1;
    unsigned maska = 0;
    
    unsigned brk = 0;
    
    while(maska1){
        if(maska1 & x)
            brk++;
        if (brk==k){
            maska = maska|maska1;
            brk = 0;
        }
            
        maska1<<=1;
    }
    
    return maska^x;
}

int main(){
    unsigned x, k;
    scanf("%u%u", &x, &k);

    x = invertujk(x, k);

    printf("%u\n", x);
exit(EXIT_SUCCESS);
}
