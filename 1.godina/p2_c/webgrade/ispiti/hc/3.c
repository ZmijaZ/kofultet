#include "cvor.h"

int suma(CVOR*g){
    if(g == NULL)
        return 0;
    return g->vrednost + suma(g->sledeci);
    
}

void obrisi(CVOR**g){
    if(*g == NULL)
        return;
    if((*g)->sledeci == NULL)
        return;
    if((*g)->vrednost > suma((*g)->sledeci)){
        CVOR*tmp = *g;
        *g = (*g)->sledeci;
        free(tmp);
        
        obrisi(g);
    }
    else
        obrisi(&(*g)->sledeci);
        
}

void dodaj(CVOR**g){
    if(*g == NULL)
        return;
    if((*g)->sledeci == NULL)
        return;
    if((*g)->vrednost > suma((*g)->sledeci)){
        dodaj_na_pocetak(&(*g)->sledeci, suma((*g)->sledeci));
        dodaj(&((*g)->sledeci)->sledeci);
        
    }
    else
        dodaj(&(*g)->sledeci);
    
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_cvor(&g, stdin);
    dodaj(&g);
    ispisi_cvor(g, stdout);

exit(EXIT_SUCCESS);
}
