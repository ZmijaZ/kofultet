#include "stablo.h"

int neparni(CVOR*g){
    if(g == NULL)
        return 0;
    if(g->levi == NULL && g->desni == NULL)
        return 0;
    if(g->levi != NULL && g->desni != NULL){
        if( (g->levi->vrednost + g->desni->vrednost) % 2 == 0)
            return neparni(g->levi) + neparni(g->desni);
        else 
            return neparni(g->levi) + neparni(g->desni) + 1;
    }
    else if(g->levi != NULL && g->desni == NULL){
        if(g->levi->vrednost % 2 == 1)
            return neparni(g->levi) + 1;
        else
            return neparni(g->levi);
    }
    else if(g->levi == NULL && g->desni != NULL){
        if(g->desni->vrednost % 2 == 1)
            return neparni(g->desni) + 1;
        else
            return neparni(g->desni);
    }
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_stablo(&g, stdin);
    printf("%d\n", neparni(g));
    ispisi_infiksno(g, stdout);

exit(EXIT_SUCCESS);
}
