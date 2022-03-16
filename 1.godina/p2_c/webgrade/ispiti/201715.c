#include "stablo.h"

int br(CVOR*g){
    if(g == NULL)
        return 0;
    if(g->vrednost % 2 == 0)
        return br(g->levi) + br(g->desni);
}
        
int main(){
    FILE*ulaz = fopen("stablo.txt", "r");
        if(ulaz == NULL)
            greska();
    
    CVOR*g = NULL;
        
    ucitaj_stablo(&g, ulaz);
    
    ispisi_infiksno(g, stdout);
    
    printf("%d\n", br(g));
exit(EXIT_SUCCESS);
}
