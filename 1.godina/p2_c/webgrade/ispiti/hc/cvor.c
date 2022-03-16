#include "cvor.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

CVOR*napravi_cvor(int broj){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
            
    novi->vrednost = broj;
    novi->sledeci = NULL;
            
    return novi;
}

void dodaj_na_pocetak(CVOR**g, int broj){
    CVOR*novi = napravi_cvor(broj);
    
    novi->sledeci = *g;
    *g = novi;
    
    return;
}

void ucitaj_cvor(CVOR**g, FILE*f){
    if(g == NULL)
       greska();
    int broj;
    while(fscanf(f, "%d", &broj) != EOF)
        dodaj_na_kraj(g, broj);
}

void ispisi_cvor(CVOR*g, FILE*f){
    fprintf(f, "[");
    while(g != NULL){
        fprintf(f, "%d", g->vrednost);
        if(g->sledeci)
            fprintf(f, ", ");
        g = g->sledeci;
    }
    fprintf(f, "]\n");
    
    return;
}

void dodaj_na_kraj(CVOR**g, int broj){
    if(*g == NULL){
        CVOR*novi = napravi_cvor(broj);
        
        *g = novi;
        
        return;
    }
    dodaj_na_kraj(&(*g)->sledeci, broj);
}

void oslobodi_cvor(CVOR*g){
    if(g){
        oslobodi_cvor(g->sledeci);
        free(g);
    }
}
