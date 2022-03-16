#include <stdio.h>
#include <stdlib.h>

#define N 4

void printbits(unsigned x){
    unsigned maska = 1 << (8*sizeof(int)-1);
    while(maska){
        printf("%c", maska&x ? '1': '0');
        maska >>=1;
    }
    printf("\n");
    return;
}

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

int ponavaljanja(unsigned x, unsigned y){
    unsigned maska1 = 1;
    unsigned maska = 0;
    int br = 0;
    for(int i = 0; i < N; i++, maska1<<=1)
        if(maska1 & y)
            maska = maska | maska1;

    for(int i = 0; i < (8*sizeof(int)-N); i++, maska<<=1){
        if( broj_jedinica(maska & x) == broj_jedinica(maska))
            br++;
    }
    return br;
}
int main(){
    unsigned x, y;
    scanf("%u%u", &x, &y);
    printf("%d\n", ponavaljanja(x, y) );
    printbits(x);
    printbits(y);

exit(EXIT_SUCCESS);
}
