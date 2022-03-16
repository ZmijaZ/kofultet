#include "stablo.h"

int dubina (CVOR*g){
    if(g == NULL)
        return 0;
    int levo = dubina(g->levi);
    int desno = dubina(g->desni);
    
    if(levo > desno)
        return 1 + levo;
    else
        return 1 + desno;
    
}

int suma(CVOR*g, int i){
    if(g == NULL)
        return 0;
    if(i == 0)
        return g->vrednost + suma(g->levi, i-1) + suma(g->desni, i-1);
    else
        return suma(g->levi, i-1) + suma(g->desni, i-1);
    
}
int main(){
    CVOR*g = NULL;
    
    ucitaj(&g, stdin);
    
    printf("%d", suma(g,dubina(g)-1));
    
printf("\n");
free(g);
exit(EXIT_SUCCESS);
}
