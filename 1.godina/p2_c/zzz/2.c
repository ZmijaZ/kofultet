#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IME 101 
#define MAX_BR 10

typedef struct{
    char ime[MAX_IME];
    int ocene[MAX_BR];
    int broj_ocena;
    float prosek;
    
    
}STUDENT;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
FILE*ulaz = fopen("studenti.txt", "r");
    if(ulaz == NULL)
        greska();
        
int n;
fscanf(ulaz, "%d", &n);
    if(n<1)
        greska();
STUDENT*niz = (STUDENT*)malloc(n*sizeof(STUDENT));
    if(niz == NULL)
        greska();
    
for(int i = 0; i<n; i++)
    niz[i].broj_ocena = 0;
    
for(int i = 0; i<n; i++){
    char prez[MAX_IME];
    fscanf(ulaz, "%s %s", niz[i].ime, prez);
    strcat(niz[i].ime, " ");
    strcat(niz[i].ime, prez);
    int j=0;
    while(fscanf(ulaz, "%d", &niz[i].ocene[j] ) != 0){
        niz[i].broj_ocena++;
        j++;
    }
    
}
for(int i =0; i<n; i++)
    printf("%s\n ", niz[i].ime);

exit(EXIT_SUCCESS);
}
