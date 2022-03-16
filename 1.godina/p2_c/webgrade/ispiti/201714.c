#include "cvor.h"


void umetni(CVOR*g){
    if(g == NULL || g->sledeci == NULL)
        greska();
    
    int zbir = 0;
    if (g->vrednost%2 == 0  && g->sledeci->vrednost%2 == 0)
        zbir = g->vrednost + g->sledeci->vrednost;
    if(zbir){
        CVOR*novi = napravi_cvor(zbir);
        CVOR*tmp = g->sledeci;
        
        g->sledeci = novi;
        novi->sledeci = tmp;
        free(tmp);
        
        umetni(novi->sledeci);
    }
    else
        umetni(g->sledeci);
}


int main(){
    CVOR*g = NULL;
    
    ucitaj_cvor(&g, stdin);
    umetni(g);
    ispisi_cvor(g, stdout);

free(g);
exit(EXIT_SUCCESS);
}
