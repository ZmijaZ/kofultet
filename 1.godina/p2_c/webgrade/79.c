#include <stdio.h>
#include <stdlib.h>

#define I 21

typedef struct {
    char id[I];
    int dug;
    
}KORISNIK;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
FILE*ulaz = fopen("saldo.txt", "r");
    if(ulaz == NULL)
        greska();
        
KORISNIK*niz = (KORISNIK*)malloc(sizeof(KORISNIK));
    if(niz == NULL)
        greska();
int alocirano = 1, i = 0;
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (KORISNIK*)realloc(niz, alocirano*sizeof(KORISNIK) );
                if(niz == NULL)
                    greska();
        }
        if(fscanf(ulaz, "%s%d", niz[i].id, &niz[i].dug) !=2)
            break;
        i++;
    }

double zbir = 0;
int d = 0;

    for(int j = 0; j<i; j++){
        if(niz[j].dug < 0){
            zbir+=abs(niz[j].dug);
            d++;
        }
    }
zbir/=d;
    for(int j = 0; j<i; j++){
        if(niz[j].dug < -zbir)
            printf("%s\n", niz[j].id);
    }

fclose(ulaz);
free(niz);
exit(EXIT_SUCCESS);
}
