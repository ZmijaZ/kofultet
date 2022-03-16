#include "stablo.h"

int broj_parnih(CVOR*g){
    if(g == NULL)
        return 0;
    if(g->levi == NULL & g->desni != NULL)
        if(g->vrednost % 2 == 0)
            return 1 + broj_parnih(g->desni);
        else
            return broj_parnih(g->desni);
        
    if(g->desni == NULL & g->levi != NULL)
        if(g->vrednost % 2 == 0)
            return 1 + broj_parnih(g->levi);
        else
            return broj_parnih(g->levi);
        
    if(g->levi != NULL & g->desni != NULL)
        if(g->vrednost % 2 == 0)
            return 2 + broj_parnih(g->levi) + broj_parnih(g->desni);
    if(g->levi == NULL & g->desni == NULL)
        return 0;
    
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_stablo(&g, stdin);
    printf("%d\n", broj_parnih(g));
    ispisi_infiksno(g, stdout); 

exit(EXIT_SUCCESS);
}
