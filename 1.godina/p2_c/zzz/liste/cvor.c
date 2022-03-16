#include "cvor.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
    return;
}

CVOR* napravi_cvor(int broj){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
    
    novi->vrednost = broj;
    novi->sledeci = NULL;
    
    return novi;
}
   
void dodaj_na_pocetak(CVOR** glava, int broj){
    CVOR* novi = napravi_cvor(broj);
    
    novi->sledeci = *glava;
    
    *glava = novi;

    return;
}

void ispisi_listu(CVOR* glava){
    printf("[");
    
    while(glava != NULL){
        printf("%d", glava->vrednost);
        
        if(glava->sledeci)
            printf(", ");
        
        glava = glava->sledeci;
    }
    printf("]\n");
    
    return;
}

void dodaj_na_kraj(CVOR** glava, int broj){
    if(*glava == NULL){
        CVOR*novi = napravi_cvor(broj);
        *glava = novi;
        return;
    }
    
    dodaj_na_kraj(&(*glava)->sledeci, broj);
    
}

void oslobodi_listu(CVOR* glava){
    if(glava){
        oslobodi_listu(glava->sledeci);
        free(glava);
        
    }
    return;
}

void ucitaj_listu(CVOR** glava, FILE*f){
    if(f == NULL)
        greska();
    int x;
    while(fscanf(f, "%d", &x)!=EOF){
        dodaj_na_kraj(glava, x);
        
    }
    
}
