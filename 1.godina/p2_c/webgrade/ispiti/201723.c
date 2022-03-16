#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}



unsigned izmeni(unsigned x){
    unsigned maska1 = 1;
    unsigned maska = 0;
    int p = 4;
    int n = 9;
    for(int i = 0; i<p; i++, maska1<<=1){
        maska = maska1|maska;
        
    }
    maska <<=8*sizeof(int)-p;
    maska = maska ^x;
    maska >>= p;
    maska <<= p;
    return maska | n ;
}

int main(){
    unsigned x;
    scanf("%u", &x);
    printf("%u\n", izmeni(x));


exit(EXIT_SUCCESS);
}
