
#include "cvor.h"

int zbir_vecih(CVOR*g){

    if(g == NULL)
        return 0;
    else
        return g->vrednost + zbir_vecih(g->sledeci);
}

void izbaci(CVOR**g){
    if((*g)->sledeci  == NULL)
        return;
    if((*g)->vrednost > zbir_vecih((*g)->sledeci) ){
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
    
    ucitaj(&g, stdin);
    izbaci(&g);
    ispisi(g, stdout);
    
free(g);
exit(EXIT_SUCCESS);
}
