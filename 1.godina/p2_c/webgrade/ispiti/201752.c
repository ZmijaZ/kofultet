#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 26

typedef struct {
    char ime1[N];
    char ime2[N];
    float rastojanje;
    int trajanje;

}LET;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int uporedi(void const *a, void const *b){
    LET p = *(LET*)a;
    LET q = *(LET*)b;
    
    if( p.rastojanje > q.rastojanje )
        return -1;
        else if( p.rastojanje < q.rastojanje )
            return 1;
        else{
            if( p.trajanje > q.trajanje)
                return 1;
            else if( p.trajanje < q.trajanje)
                return -1;
            else 
                return 0;
            
        }
}

int main(){
    FILE*ulaz = fopen("letovi.txt", "r");
        if(ulaz == NULL)
            greska();
    LET*niz = (LET*)malloc(sizeof(LET));
        if(niz == NULL)
            greska();
    int alocirano = 1, i = 0;
    
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (LET*)realloc(niz, alocirano*sizeof(LET));
                if(niz == NULL)
                    greska();
        }
        if(fscanf(ulaz, "%s%s%f%d", niz[i].ime1, niz[i].ime2, &niz[i].rastojanje, &niz[i].trajanje) != 4)
            break;
        i++;
    }
        
    qsort(niz, i, sizeof(LET), uporedi);
        
    for(int j = 0; j<i; j++){
        if(niz[j].rastojanje * niz[j].trajanje < 0)
            greska();
        printf("%s %s %.2f %d\n", niz[j].ime1, niz[j].ime2, niz[j].rastojanje, niz[j].trajanje);
    }

free(niz);
niz = NULL;
fclose(ulaz);
exit(EXIT_SUCCESS);
}
