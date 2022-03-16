#include "cvor.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

CVOR*napravi_cvor(int broj){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
            
    novi->sledeci = NULL;
    novi->vrednost = broj;
    
    return novi;
}

void dodaj_na_pocetak(CVOR*g, int broj){
    CVOR*novi = napravi_cvor(broj);
    
    novi->sledeci = g;
    
    g = novi;
}

void ispisi (CVOR*g, FILE*f){
    fprintf(f, "[");
    
    while(g != NULL){
        fprintf(f, "%d", g->vrednost);
        if(g->sledeci)
            fprintf(f, ", ");
        g = g->sledeci;
    }
    fprintf(f, "]\n");
}

void dodaj_na_kraj(CVOR**g, int broj){
    if(*g == NULL){
        CVOR*novi = napravi_cvor(broj);
        
        *g = novi;
        
        return;
    }
    dodaj_na_kraj(&(*g)->sledeci, broj);
}

void ucitaj (CVOR**g, FILE*f){
    if (g == NULL)
        return;
    int x;
    while(fscanf(f, "%d", &x) != EOF)
        dodaj_na_kraj(g, x);
}

void oslobodi(CVOR*g){
    if(g){
        oslobodi(g->sledeci);
        free(g);
    }
}
