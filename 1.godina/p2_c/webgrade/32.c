#include <stdio.h>
#include <stdlib.h>

#define N 31
#define I 21

typedef struct{
    char marka[N];
    char model[N];
    int cena;

}AUTO;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char**argv){
    if(argc != 2)
        greska();
    int cena = atoi(argv[1]);
    
    FILE*ulaz = fopen("automobili.txt", "r");
        if(ulaz == NULL)
            greska();
    
    int n;
    fscanf(ulaz, "%d", &n);
    AUTO*niz = (AUTO*)malloc(n*sizeof(AUTO));
        if(niz == NULL)
            greska();
            
    for(int i = 0; i<n; i++){
        fscanf(ulaz, "%s%s%d\n", niz[i].marka, niz[i].model, &niz[i].cena);
        fprintf(stdout, "%s %s %d\n", niz[i].marka, niz[i].model, niz[i].cena);
    }

exit(EXIT_SUCCESS);
}
