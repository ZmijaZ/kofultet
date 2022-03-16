#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int*alociraj(int n){
    int*a = (int*)malloc(n*sizeof(int));
        if(a == NULL)
            greska();
    return a;
}

void inicijalizuj(int*a, int n){
    int i;
    for(i = 0; i<n; i++)
        scanf("%d", (a+i));
        
    return;
}

void ispisi(int*a, int n){
    int i;
    for(i = 0; i<n; i++)
        printf("%d ", *(a+i));
    
    printf("\n");
    return;
}

void f12(int*a, int n){
    if(n==0)
        return;
    if( *(a-1) + *(a+1) == *a )
        *a = 0;
    
    f12(a+1, n-1);
}

int main(){
    int  n;
    scanf("%d", &n);

int*niz = alociraj(n);

inicijalizuj(niz, n);
f12(niz+1, n-2);
ispisi(niz, n);

free(niz);
exit(EXIT_SUCCESS);
}
