#include <stdio.h>
#include <stdlib.h>

void greska (void){
    fprintf(stderr,"-1");
    exit(EXIT_FAILURE);
}
void inicijalizuj(int* a, int n){
    for(int i =0; i<n; i++)
        scanf("%d", a+i);
}

int f3(int *a, int na, int suma_prethodnih){
    if(na == 0)
        return 0;
    if(suma_prethodnih<*a)
    *a = 0;   
    return (*a)+(f3(a+2, na-1, suma_prethodnih+(*a)));

}

int main(){
int n;
scanf("%d", &n);
    if(n<0)
        greska();
int *niz = (int*)malloc(n*sizeof(int));
inicijalizuj(niz, n);

printf("%d\n", f3(niz, n, 0) );
for(int i =0; i<n; i++)
    printf("%d ", *(niz+i));
printf("\n");
free(niz);
exit(EXIT_SUCCESS);
}
