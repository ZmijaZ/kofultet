#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double x;
    double y;
    
}KOOD;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void selection(KOOD*niz, int n){
    int i, j, min;
    KOOD pom;
    
    for(i = 0; i<n; i++){
        min = i;
        for(j = i+1; j<n; j++)
            if(niz[j].x < niz[min].x)
                min = j;
        pom.x = niz[min].x;
        niz[min].x = niz[i].x;
        niz[i].x = pom.x;
        
        pom.y = niz[min].y;
        niz[min].y = niz[i].y;
        niz[i].y = pom.y;
    }
    
    return;
}

int main(int argc, char**argv){

    if(argc!=2)
        greska();
    
FILE*ulaz = fopen(argv[1], "r");
        if(ulaz == NULL)
            greska();

KOOD*niz = (KOOD*)malloc(sizeof(KOOD));
        if(niz == NULL)
            greska();
        
int alocirano = 1; int i = 0;
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (KOOD*)realloc(niz, alocirano*sizeof(KOOD));
                if(niz == NULL)
                    greska();
        }
        if(fscanf(ulaz, "%lf%lf", &niz[i].x, &niz[i].y)!=2)
            break;
        i++;
    }
    int n = i;
    
KOOD*pom = (KOOD*)malloc(n*sizeof(KOOD));
    if(pom == NULL)
        greska();
    
    selection(niz, n);
    
    for(i = 0; i<n; i++)
        printf("%.2lf %.2lf\n", niz[i].x, niz[i].y);
            
exit(EXIT_SUCCESS);
}
