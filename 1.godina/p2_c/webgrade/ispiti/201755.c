#include "stablo.h"

int parni(CVOR*g){
    if(g == NULL)
        return 0;
    if(g->vrednost % 2 == 0){
        if(g->levi->vrednost % 2 == 0 && g->desni->vrednost % 2 == 0)
            return 1 + parni(g->levi) + parni(g->desni);
    }
    else
        return parni(g->levi) + parni(g->desni);
}

int main(){
    CVOR*g = NULL;
    
    ucitaj(&g, stdin);
    
    printf("%d\n", parni(g));
    
exit(EXIT_SUCCESS);
}
