#include <stdio.h>
#include <stdlib.h>

void printbits(unsigned x){
    unsigned maska = 1 << (8*sizeof(int)-1);
    while(maska){
        printf("%c", maska&x ? '1' : '0');
        maska>>=1;
    }
    printf("\n");
}

unsigned izmeni(unsigned x){
    unsigned maska1 = 2;
    unsigned maska = 0;
    unsigned maskal;
    unsigned maskad;

    while(maska1){
        if(maska1 & x){
            maskad = maska1>>1;
            maskal = maska1<<1;
            if((maskad ^ maska1) && (maskal ^ maska1) )
                maska = maska&maska1;
        }
        else if(! (maska1 & x) ){
            maskad = maska1>>1;
            maskal = maska1<<1;
            if( !(maskad ^ maska1) && !(maskal ^ maska1) )
                maska = maska|maska1;
        }
        maska1<<=1;
    }
    return maska;
}

int main(){
    unsigned x;
    scanf("%u", &x);
    printbits(x);
    printbits(izmeni(x));

exit(EXIT_SUCCESS);
}
