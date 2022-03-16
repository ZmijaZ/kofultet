#include "stabla.h"

int uStablu(CVOR*koren, int broj){
    if(koren == NULL)
        return NULL;
    if(broj == koren->vrednost)
        return 1;
    else if(broj > koren->vrednost)
       return uStablu(koren->desni, broj);
    else
       return uStablu(koren->levi, broj);
    
    
}

int main(){
    CVOR*koren = NULL;
    
    ucitaj_stablo(&koren, stdin);
    
    ispisi(koren, stdout);
    printf("\n");
    
    if(
    
oslobodi(koren);
exit(EXIT_SUCCESS);
}
