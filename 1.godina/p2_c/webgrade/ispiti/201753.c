#include <stdio.h>
#include <stdlib.h>


int broj_jedinica(unsigned x){
    int br = 0;
    unsigned maska = 1;
    while(maska){
        if(maska & x)
            br++;
        maska<<=1;
    }
    return br;
}

unsigned prvi_veci(unsigned x){
    return ~x;
    
}

unsigned drugi_veci(unsigned x, unsigned y){
    unsigned maska1 = 1;
    unsigned maska = 0;
    while(maska1){
        if( (maska1&x) && !(maska1&y))
            maska = maska | maska1;
        maska1<<=1;
    }
    return maska;
}

int main(){
    unsigned x, y;
    scanf("%u%u", &x, &y);

    if(broj_jedinica(x) > broj_jedinica(y))
        printf("%u\n", prvi_veci(x));
    else
        printf("%u\n", drugi_veci(x, y));

exit(EXIT_SUCCESS);
}
