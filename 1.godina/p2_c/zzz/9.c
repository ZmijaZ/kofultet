#include <stdio.h>
#include <stdlib.h>

void ispis_bita(int x){
    unsigned maska = 1 << (sizeof(int)*8 -1);
    while(maska){
        printf("%c", x&maska ? '1': '0');
        maska >>= 1;
        
    }
    printf("\n");
}

void provera(int x, int k){
    unsigned maska = 1 << k;
    if(maska&x)
        printf("Ima keca\n");
    else
        printf("Nema keca\n");
    
}

unsigned get_bits(int x, int n, int p){
    unsigned mask = 1;
    unsigned mask1 = 0;
    int i;
    for(i = 0; i<n; i++, mask<<=1)
        mask1 = mask | mask1;
    mask1<<=p;
    return x & mask1;
    
}

unsigned set_bits(int x, int p, int n, unsigned y){
    unsigned mask = 1;
    unsigned mask1 = 0;
    unsigned pomoc1;
    int i;
    for(i = 0; i<n; i++, mask<<=1)
        mask1 = mask1 | mask;
    pomoc1 = y&mask1;
    pomoc1<<=p;
    return pomoc1;
    }
    

int suma_bitova(int x){
    unsigned maska = 1;
    int suma = 0;
    while(maska){
        suma+= (x&maska ? 1 : 0);
        maska <<= 1;
    }
    return suma;
}


int main(){
    int x, n, p;
    int y;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &p);
    scanf("%d", &n);
    
    unsigned z = set_bits(x, p, n, y);
    ispis_bita(x);
    ispis_bita(z);
    ispis_bita(y);
    
}
