#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21

typedef struct{
    char ime[N];
    double cena;
    double kolicina;
}PROIZVOD;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void insertion(double*a, int n, PROIZVOD*niz){
    int i, j;
    double pom;
    PROIZVOD tmp;
    for(i = 1; i<n; i++){
        pom = a[i];
        strcpy(tmp.ime, niz[i].ime);
        tmp.cena = niz[i].cena;
        tmp.kolicina = niz[i].kolicina;
        
        for(j = i; j>0 && a[j-1] < pom; j--){
            a[j] = a[j-1];
            strcpy(niz[j].ime, niz[j-1].ime);
            niz[j].cena = niz[j-1].cena;
            niz[j].kolicina = niz[j-1].kolicina;
            
        }
            
        a[j] = pom;
        strcpy(niz[j].ime, tmp.ime);
        niz[j].cena = tmp.cena;
        niz[j].kolicina = tmp.kolicina;
    }
    return;
}

int main(){

    FILE*ulaz = fopen("proizvodi.txt", "r");
        if(ulaz == NULL)
            greska();
            
    int n, i;
    fscanf(ulaz, "%d", &n);    
        
    PROIZVOD*niz = (PROIZVOD*)malloc(n*sizeof(PROIZVOD));
        if(niz == NULL)
            greska();
    double*cena = (double*)malloc(n*sizeof(double));
        if(cena == NULL)
            greska();
    for(i = 0; i<n; i++){
        fscanf(ulaz, "%s%lf%lf", niz[i].ime, &niz[i].cena, &niz[i].kolicina);
        cena[i] = niz[i].kolicina * niz[i].cena;
        }
        
    insertion(cena, n, niz);
    
    for(i = 0; i<n; i++)
        printf("%s %.2lf %.2lf %.2lf\n", niz[i].ime, niz[i].cena, niz[i].kolicina, cena[i]);
        
fclose(ulaz);
free(niz);
free(cena);
exit(EXIT_SUCCESS);
}
