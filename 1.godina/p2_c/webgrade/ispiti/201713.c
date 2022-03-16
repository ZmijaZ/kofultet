#include <stdio.h>
#include <stdlib.h>


unsigned invertujSvakiTreci(unsigned x){
    unsigned maska1 = 1;
    unsigned maska = 0;
    
    unsigned i = 1;
    
    while(maska1){
        if( !(maska1 & x) && (i%3 == 0) )
        maska = maska|maska1;
        maska1<<=1;
        i++;
    }

    return maska^x ;
}

int main(){
    unsigned x;
    scanf("%u", &x);
    
    printf("%u\n", invertujSvakiTreci(x));
    
exit(EXIT_SUCCESS);
}
