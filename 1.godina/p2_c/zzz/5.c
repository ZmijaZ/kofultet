#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
}

int izbaci_parne(int x){
    if(x == 0)
        return 0;
    if(x%2 == 1)
        return izbaci_parne(x/10)*10 + x%10;
    else
        return izbaci_parne(x/10);

}

int*alociraj (int n){
    int*a = (int*)malloc(n*sizeof(int));
        if(a == NULL)
            greska();
    return a;
}

void inicijalizuj(int*a, int n){
    int i;
    for(i = 0; i<n; i++)
        scanf("%d", a+i);
    return;
}

int maksimum_niza(int*a, int n){
    if(n == 0)
        return *a;
    int najveca_levo = maksimum_niza(a+1, n-1);
    if(*a > najveca_levo)
        return *a;
    else
        return najveca_levo;
}

int main(){
int x; int p = 1;
    scanf("%d", &x);
    if(x<0)
        greska();
int *niz = alociraj(x);
    if(niz == NULL)
        greska();
inicijalizuj(niz, x);

printf("%d\n",maksimum_niza(niz, x-1) );

exit(EXIT_SUCCESS);
}
