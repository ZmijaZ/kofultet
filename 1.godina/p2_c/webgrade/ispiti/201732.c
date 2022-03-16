#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 16

typedef struct {
    char sifra[N];
    int dan;
    int mesec;
    int godina;
}ISPIT;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int uporedi(const void *a, const void *b){
    ISPIT p = *(ISPIT*)a; 
    ISPIT q = *(ISPIT*)b;
    
    if(p.godina > q.godina)
        return 1;
    else if(p.godina < q.godina)
        return -1;
    else{
        if(p.mesec > q.mesec)
            return 1;
        else if(p.mesec < q.mesec)
            return -1;
        else{
            if(p.dan > q.dan)
                return 1;
            else if(p.dan < q.dan)
                return -1;
            else{
                if(strcmp(p.sifra, q.sifra) > 0)
                    return -1;
                else if(strcmp(p.sifra, q.sifra) < 0)
                    return 1;
                else return 0;
                
            }
        }
        
    }
    
}

int main(){
    FILE*ulaz = fopen("ispiti.txt", "r");
        if(ulaz == NULL)
            greska();

    ISPIT*niz = (ISPIT*)malloc(sizeof(ISPIT));
        if(niz == NULL)
            greska();
    
    int alocirano = 1, i = 0;
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (ISPIT*)realloc(niz, alocirano*sizeof(ISPIT));
                if(niz == NULL)
                    greska();

        }
        if(fscanf(ulaz, "%s%d%d%d", niz[i].sifra, &niz[i].dan, &niz[i].mesec, &niz[i].godina) != 4)
            break;
        i++;
    }

    for(int j = 0; j<i; j++)
        if(niz[j].dan*niz[j].godina*niz[j].mesec < 0)
            greska();

    qsort(niz, i, sizeof(ISPIT), uporedi);
    for(int j = 0; j<i; j++)
        printf("%s\n", niz[j].sifra);
    
        
free(niz);
fclose(ulaz);
exit(EXIT_SUCCESS);
}
