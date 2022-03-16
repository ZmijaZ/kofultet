#include <stdio.h>
#include <stdlib.h>
#include "polinom.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int* unos(int*n){
    int i;
    scanf("%d", n);
    int*a = (int*)malloc(((*n)+1)*sizeof(int));
        if(a == NULL)
            greska();
    for(i=0; i<((*n)+1); i++)
        scanf("%d", a+i);
    return a;
}

int suma_polinoma(int* a, int n, int* b, int m, int** c){
    int veci, manji, i;
    if(n>m){
        veci = n;
        manji = m;
    }
    else if(n<m){
        veci = m;
        manji = n;
    }
    int *niz = (int*)malloc((n+1)*sizeof(int));
        if(niz == NULL)
            greska();
    for(i = 0; i<=manji; i++)
        *(niz+i) = *(a+i) + *(b+i);
    for(i = manji+1; i<= veci; i++){
        if(n == veci)
            *(niz+i) = *(a+i);
        else
            *(niz+i) = *(b+i);
    }
    *c = niz;
    return veci;
}


void ispisi(int*a, int n){
    int i;
    printf("%d ", *a);
    for(i = 1; i<=n; i++){
        if(*(a+i)==0)
        continue;
        if(*(a+i)< 0)
            printf("- ");
        else
            printf("+ ");
        if(i>1)
            printf("%d*x^%d ", abs(*(a+i)), i);
        else
            printf("%d*x ", abs(*(a+i)) );
    }
    return;
}
