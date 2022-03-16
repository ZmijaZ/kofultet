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

unsigned invertujSvakiTreci(unsigned x){
    unsigned maska1 = 1;
    unsigned maska = 0;
    int i = 0;
    while(maska1){
        if(i % 3 == 0)
            maska = maska1 | maska;
        maska1<<=1;
        i++;
    }
    
    return maska ^ x;
}

int main(){
    int x;
    scanf("%d", &x);

    x = invertujSvakiTreci(x);

    printf("%d\n", x);
exit(EXIT_SUCCESS);
}
