#include <stdio.h>
#include <stdlib.h>

void printbits(int x){
    unsigned maska = 1 << (8*sizeof(int)-1);
    while(maska){
        printf("%c", maska & x ? '1' : '0');
        maska >>=1;
        
    }
    printf("\n");
}

int jedinica(int x, int k){
    unsigned maska = 1 << k;
    
    return x&maska;
}

int ubaci(int x, int k){
    unsigned maska = 1 << k;
    
    return x|maska;
}

int suma_bitova(int x){
    unsigned maska = 1;
    int suma = 0;
    while(maska){
        if(x & maska)
            suma++;
        maska <<=1;
    }
    return suma;
}

int get_bits(int x, int n, int p){
    unsigned maska = 1;
    unsigned maska1 = 0;
    for(int i = 0; i<n; i++, maska<<=1){
        maska1 |= maska;
    }
    maska1 = maska1<<p;
    
    return maska1 &x;
}

unsigned set_bits(int x, int p, int n, int y){
    unsigned maska1 = 1;
    unsigned maska = 0;
    unsigned maska2 = 0;
    
    for(int i = 0; i<n; i++, maska1<<=1)
        maska = maska|maska1;
    
    maska1 = 1;
    for(int i = 0; i<p; i++, maska1<<=1)
        maska2 = maska2|maska1;
    maska = maska &y;
    maska <<= p;
    
    return maska | (maska2 & x);
}

unsigned invert_bits(unsigned x, int p, int n){
    unsigned maska1 = 1;
    unsigned maska = 0;
    
    for(int i = 0; i<n; i++, maska1<<=1)
        maska = maska|maska1;
        
    
    return (maska <<p) ^ x;
}

int main(){
    int x, n, p;
    scanf("%d%d%d", &x, &n, &p);
    printbits(x);
    
    printbits(invert_bits(x, p, n));
    
exit(EXIT_SUCCESS);
}
