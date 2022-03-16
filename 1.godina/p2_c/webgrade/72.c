#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21
#define M 51

typedef struct{
    char barkod[N];
    char ime[M];
    char proizvodjac[M];
    double cena;

}ARTIKAL;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int poredi(void const *a, void const*b){
    char *bk = (char*)a;
    ARTIKAL niz = *(ARTIKAL*)b;
    return strcmp(bk, niz.barkod);
}

int main(){
char*ime1 = (char*)malloc(51*sizeof(char));
    if(ime1 == NULL)
        greska();

scanf("%s", ime1);    
    
FILE*ulaz = fopen(ime1, "r");
    if(ulaz == NULL)
        greska();
    
ARTIKAL*niz = (ARTIKAL*)malloc(sizeof(ARTIKAL));
    if(niz == NULL)
        greska();
    int alociranoa = 1; int j = 0;
    while(1){
        if(alociranoa == j){
            alociranoa++;
            niz = (ARTIKAL*)realloc(niz, alociranoa*sizeof(ARTIKAL));
                if(niz == NULL)
                    greska();
        }
        
        if(fscanf(ulaz, "%s%s%s%lf", niz[j].barkod, niz[j].ime, niz[j].proizvodjac, &niz[j].cena) != 4)
            break;
        j++;
    }
        
       
char barkod[N];
double cena = 0;
while(1){
    scanf("%s", barkod);
    if(strcmp(barkod, "0") == 0)
        break;
    ARTIKAL*p = bsearch(barkod, niz, j, sizeof(ARTIKAL), poredi);
    if(p == NULL)
        printf("Nepostojeci barkod\n");
    else
        cena+=p->cena;
}
printf("%g\n", cena);

free(niz);
fclose(ulaz);
exit(EXIT_SUCCESS);
}
