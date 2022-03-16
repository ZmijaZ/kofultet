#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int* alociraj(int n){
    int*a = (int*)malloc(n*sizeof(int));
        if(a==NULL)
            greska();
    return a;
}

void ucitaj(int *a, int n){
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
}

int maksimum_niza(int* a, int n){
    if(n==0)
        return *a;
    int najveci = maksimum_niza(a,n-1);

    if(a[n]>najveci)
        return a[n];
    else
        return najveci;
}


int main(){

int n; 
scanf("%d", &n);
    if(n<0)
        greska();
if(n==0)
    exit(EXIT_SUCCESS);
    
int* niz;
niz = alociraj(n);

ucitaj(niz, n);

printf("%d\n", maksimum_niza(niz,n-1));

exit(EXIT_SUCCESS);
}
