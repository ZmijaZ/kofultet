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

void dodaj_na_pocetak (CVOR** glava, int broj){
    CVOR*novi = napravi_cvor(broj);
    
    novi->sledeci = *glava;
    *glava = novi;

}

void ispisi_listu(CVOR*glava, FILE*f){
    fprintf(f, "[");
    while(glava != NULL){
        fprintf(f, "%d", glava->vrednost);
        if(glava->sledeci)
            fprintf(f, ", ");
            
        glava = glava->sledeci;
    }
    fprintf(f, "]\n");
}

void dodaj_na_kraj(CVOR**glava, int broj){
    if(*glava == NULL){
        CVOR*novi = napravi_cvor(broj);
        
        *glava = novi;
        
        return;
    }
    dodaj_na_kraj(&(*glava)->sledeci, broj);
}

void ucitaj_listu(CVOR** glava, FILE*f){
    if(f == NULL)
        greska();
    
    int x;
    while(fscanf(f, "%d", &x) != EOF)
        dodaj_na_kraj(glava, x);
    

}

void oslobodi_listu(CVOR*glava){
    if(glava){
        oslobodi_listu(glava->sledeci);
        free(glava);
    }

}
