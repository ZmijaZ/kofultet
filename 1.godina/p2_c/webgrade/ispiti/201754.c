#include "cvor.h"

void obrisi(CVOR**g){
    if(*g == NULL)
        return;
    if((*g)->sledeci == NULL)
        return;
    CVOR* naredni = (*g)->sledeci->sledeci;
        if(naredni == NULL)
            return;
    if((*g)->sledeci->vrednost < ((*g)->vrednost + naredni->vrednost )){
        CVOR*tmp = (*g)->sledeci;
        (*g)->sledeci = naredni;
        free(tmp);
        obrisi(g);
    }
    else
        obrisi(&(*g)->sledeci);
    
}

int main(){
    CVOR*g = NULL;
    
    ucitaj(&g, stdin);
    obrisi(&(g));
    ispisi(g, stdout);

oslobodi(g);
exit(EXIT_SUCCESS);
}
