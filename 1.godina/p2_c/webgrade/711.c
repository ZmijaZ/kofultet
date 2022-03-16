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

void f11(int*a, int n, int x){
    if(n<0)
        return;
    if( *a + *(a+1) == x )
        *a = 0;

    else if( *(a+1) + *(a+2) == x)
        *(a+1) = 0;
    
    f11(a+1, n-1, x);
}

int main(){
    int x, n;
    scanf("%d%d", &x, &n);

int*niz = alociraj(n);

inicijalizuj(niz, n);

f11(niz, n-2, x);
ispisi(niz, n);

free(niz);
exit(EXIT_SUCCESS);
}
