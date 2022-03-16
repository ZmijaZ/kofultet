#include "cvor.h"

void izbaci(CVOR**g){
    if(*g == NULL)
        return;
    if((*g)->sledeci == NULL)
        return;
    if( ((*g)->vrednost + (*g)->sledeci->vrednost) == 0){
        CVOR*tmp = *g;
        *g = (*g)->sledeci;
        free(tmp);
        izbaci(g);
    }
    else
        izbaci(&(*g)->sledeci);
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_cvor(&g, stdin);
    izbaci(&g);
    ispisi_cvor(g, stdout);

exit(EXIT_SUCCESS);
}
