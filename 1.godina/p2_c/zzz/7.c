#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21

typedef struct {
    char ime[N];
    char prezime[N];
    char smer;
    float ocena;
    
}STUDENT;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int binarna_rekurzivno(STUDENT*a, char*x, int l, int d){
    if(l>d)
        return -1;
    int s = (l+d)/2;
    if(strcmp(a[s].prezime, x) == 0)
        return s;
    else if(strcmp(a[s].prezime, x) > 0)
        return binarna_rekurzivno(a, x, l, s-1);
    else
        return binarna_rekurzivno(a, x, s+1, d);
}

int poredi(const void*a, const void*b){
    char*prezime = (char*)a;
    STUDENT s = *(STUDENT*)b;
    return strcmp(prezime, s.prezime);
}

int main(){
FILE*ulaz = fopen("studenti.txt", "r");
    if(ulaz == NULL)
        greska();
int n, i;
    fscanf(ulaz, "%d", &n);
        if(n<1)
            greska();
        
char*prezime = (char*)malloc(N*sizeof(char));
    if(prezime == NULL)
        greska();
scanf("%s", prezime);
        
STUDENT *niz = (STUDENT*)malloc(n*sizeof(STUDENT));
    if(niz == NULL)
        greska();
for(i = 0; i<n; i++)
    fscanf(ulaz, "%s %s %c %f", niz[i].ime, niz[i].prezime, &niz[i].smer, &niz[i].ocena);
int br = binarna_rekurzivno(niz, prezime, 0, n);
if(br >= 0)
printf("%s %s %c %g\n", niz[br].ime, niz[br].prezime, niz[br].smer, niz[br].ocena);


STUDENT* p = bsearch(prezime, niz, n, sizeof(STUDENT), poredi);
    
printf("%ld\n", p - niz);


exit(EXIT_SUCCESS);
}
