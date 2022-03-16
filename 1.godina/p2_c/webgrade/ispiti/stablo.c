#include "stablo.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

CVOR*napravi_cvor(int broj){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
            
    novi->levi = NULL;
    novi->desni = NULL;
    novi->vrednost = broj;
    
    return novi;
}

void dodaj_u_stablo(CVOR**g, int broj){
    if(*g == NULL){
        *g = napravi_cvor(broj);
        return;
    }
    
    
    if(broj > (*g)->vrednost)
        dodaj_u_stablo(&(*g)->desni, broj);
    else
        dodaj_u_stablo(&(*g)->levi, broj);
}

void ucitaj(CVOR**g, FILE*f){

    int x;
    while(fscanf(f, "%d", &x) != EOF)
        dodaj_u_stablo(g, x);
}

void ispisi_infiksno(CVOR*g, FILE*f){
    if(g != NULL){
    ispisi_infiksno(g->levi, f);
    fprintf(f, "%d ", g->vrednost);
    ispisi_infiksno(g->desni, f);
    }
}

void ispisi_prefiksno(CVOR*g, FILE*f){
    if(g != NULL){
    fprintf(f, "%d ", g->vrednost);
    ispisi_prefiksno(g->levi, f);
    ispisi_prefiksno(g->desni, f);
    }
}

void ispisi_postfiksno(CVOR*g, FILE*f){
    if(g != NULL){
    ispisi_postfiksno(g->levi, f);
    ispisi_postfiksno(g->desni, f);
    fprintf(f, "%d ", g->vrednost);
    }
}

void oslobodi(CVOR*g){
    if(g){
        oslobodi(g->levi);
        oslobodi(g->desni);
        free(g);
        
    }
    
}
