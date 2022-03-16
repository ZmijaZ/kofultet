#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);

}

typedef struct {
    int dan;
    int mesec;
    int godina;
}DATUM;

int uporedi(const void*p, const void*q){
    DATUM a = *(DATUM*)p;
    DATUM b = *(DATUM*)q;
        if(a.godina > b.godina)
            return 1;
        else if(a.godina < b.godina)
            return -1;
        else{
            if(a.mesec > b.mesec)
                return 1;
            else if(a.mesec < b.mesec)
                return -1;
            else{
                if(a.dan > b.dan)
                    return 1;
                else if(a.dan < b.dan)
                    return -1;
                else
                    return 0;
            }
        }   
}

int main(){
    FILE*ulaz = fopen("datum.txt", "r");
        if(ulaz == NULL)
            greska();

    DATUM*niz = (DATUM*)malloc(sizeof(DATUM));
        if(niz == NULL)
            greska();
            
    int alocirano = 1; int i = 0;
    
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (DATUM*)realloc(niz, alocirano*sizeof(DATUM));
                if(niz == NULL)
                    greska();
        }
        if(fscanf(ulaz, "%d.%d.%d.", &niz[i].dan, &niz[i].mesec, &niz[i].godina) != 3)
            break;
        i++;
    }
    
    qsort(niz, i, sizeof(DATUM), uporedi);
    
    for(int j = 0; j<i; j++){
        if(niz[j].dan > 31 || niz[j].dan< 0 
            || niz[j].mesec > 12 || niz[j].mesec < 1
            || niz[j].godina > 9999 || niz[j].godina < 0)
                greska();
        printf("%d.%d.%d\n", niz[j].dan, niz[j].mesec, niz[j].godina);
    }

    
    
fclose(ulaz);
free(niz);
niz = NULL;
exit(EXIT_SUCCESS);
}
