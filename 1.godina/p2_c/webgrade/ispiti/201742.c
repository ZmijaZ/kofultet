#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21

typedef struct {
    char ime[N];
    float cena;
    int kolicina;

}PROIZVOD;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int uporedi(void const *a, void const *b){
    PROIZVOD p = *(PROIZVOD*)a;
    PROIZVOD q = *(PROIZVOD*)b;
    
    if( (p.cena * p.kolicina) > (q.cena * q.kolicina) )
        return 1;
        else if( (p.cena * p.kolicina) < (q.cena * q.kolicina) )
            return -1;
        else{
            if(strcmp(p.ime, q.ime) > 0)
                return -1;
            else if(strcmp(p.ime, q.ime) < 0)
                return 1;
            else 
                return 0;
            
        }
}

int main(){
    FILE*ulaz = fopen("proizvodi.txt", "r");
        if(ulaz == NULL)
            greska();
    PROIZVOD*niz = (PROIZVOD*)malloc(sizeof(PROIZVOD));
        if(niz == NULL)
            greska();
    int alocirano = 1, i = 0;
    
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (PROIZVOD*)realloc(niz, alocirano*sizeof(PROIZVOD));
                if(niz == NULL)
                    greska();
        }
        if(fscanf(ulaz, "%s%f%d", niz[i].ime, &niz[i].cena, &niz[i].kolicina) != 3)
            break;
        i++;
    }
        
    qsort(niz, i, sizeof(PROIZVOD), uporedi);
        
    for(int j = 0; j<i; j++){
        if(niz[j].cena * niz[j].kolicina < 0)
            greska();
        printf("%s %.2f\n", niz[j].ime, niz[j].cena * niz[j].kolicina);
    }

free(niz);
niz = NULL;
fclose(ulaz);
exit(EXIT_SUCCESS);
}
