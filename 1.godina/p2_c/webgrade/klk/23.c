#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int *alociraj(int n){
    int *a = (int*)malloc(n*sizeof(int));
        if(a == NULL)
            greska();
    return a;
}

void f3(int *a, int na){
    if(na == 0)
        return;
    if( (*(a+1) % 2 == 0) && (*a % 2 == 0) && *(a+1) )
        (*a)--;
    f3(a+1, na-1);
        
}

int main(){
int n;
scanf("%d", &n);
    if(n<0)
        greska();
int *niz = alociraj(n);

for(int i=0; i<n; i++)
    scanf("%d", (niz+i));
f3(niz, n);
for(int i=0; i<n; i++)
    printf("%d ", *(niz+i));
printf("\n");
free(niz);
exit(EXIT_SUCCESS);
}
