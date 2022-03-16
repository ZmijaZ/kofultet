#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void inicijalizuj(int *a, int n){
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
}

int izmeniNiz(int *niz, int n){
    if(n==0 || n ==1)
        return 0;
    int tmp;
    if(( (*niz) + *(niz+n-1) ) % 2 == 1){
        tmp = *niz;
        *niz = *(niz+n-1);
        *(niz+n-1) = tmp;
        }
    return izmeniNiz(niz+1, n-2);
}

int main(){
int n;
scanf("%d", &n);
    if(n<0)
        greska();
int *niz = (int*)malloc(n*sizeof(int));
    if(niz == NULL)
        greska();
        
inicijalizuj(niz,n);
izmeniNiz(niz, n);
for(int i=0; i<n; i++)
    printf("%d ", *(niz+i));
printf("\n");
free(niz);
exit(EXIT_SUCCESS);
}
