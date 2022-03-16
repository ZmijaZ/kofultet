#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void inicijalizuj(int **a, int n, FILE*f){
    int i, j;
    for(i = 0; i<n; i++)
        for(j = 0; j<n; j++)
            fscanf(f, "%d", &a[i][j]);
            
    return;
}

void ispisi(int **a, int n){
    int i, j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return;
}

int main(){
    FILE*ulaz = fopen("matrica.txt", "r");
        if(ulaz == NULL)
            greska();
            
    int n, i, j, p;
    fscanf(ulaz, "%d", &n);
    if(n < 1)
        greska();
        
    int**matrica = (int**)malloc(n*sizeof(int*));
        if(matrica == NULL)
            greska();
    for(i = 0; i<n; i++){
        matrica[i] = (int*)malloc(n*sizeof(int));
            if(matrica[i] == NULL)
                greska();
    }
        
    inicijalizuj(matrica, n, ulaz);
    
    for(i = 0; i<n; i++){
        p = 1;
        for(j = 1; j<n; j++){
            if(matrica[i][j] < matrica[i][j-1])
                p = 0;
        }
        if(p == 1)
            printf("%d ", i);
    }
    
printf("\n");
fclose(ulaz);
for(i = 0; i<n; i++)
    free(matrica[i]);
free(matrica);
exit(EXIT_SUCCESS);
}
