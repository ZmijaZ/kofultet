#include "stablo.h"

int proizvod(CVOR*g, int i){
    if(g == NULL)
        return 1;
    if(i % 2 == 0)
        return g->vrednost * proizvod(g->levi, i+1) * proizvod(g->desni, i+1);
    else
        return proizvod(g->levi, i+1) * proizvod(g->desni, i+1);
    
    
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_stablo(&g, stdin);
    printf("%d\n", proizvod(g, 0));
    ispisi_infiksno(g, stdout);

exit(EXIT_SUCCESS);
}
