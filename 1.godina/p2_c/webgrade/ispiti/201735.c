#include "stablo.h"


int main(){
    CVOR*g = NULL;
    
    ucitaj(&g, stdin);
    
    ispisi_infiksno(g, stdout);
    
free(g);
exit(EXIT_SUCCESS);
}
