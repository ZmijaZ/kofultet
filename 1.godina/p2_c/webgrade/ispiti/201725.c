#include "stablo.h"

int broj_neparnih(CVOR*g){
    if(g == NULL)
        return 0;
    if( (g->levi->vrednost + g->desni->vrednost) % 2 == 1)
        return 1 + broj_neparnih(g->levi) + broj_neparnih(g->desni);
    else{
        return broj_neparnih(g->levi) + broj_neparnih(g->desni);
    }
    
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_stablo(&g, stdin);
    
    printf("%d", broj_neparnih(g));

printf("\n");
free(g);    
exit(EXIT_SUCCESS);
}
