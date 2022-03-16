#include "cvor.h"

void umetni(CVOR**g){
    if(*g == NULL)
        return;
    if((*g)->sledeci == NULL)
        return;
    if((*g)->vrednost %2 == 0 && (*g)->sledeci->vrednost %2 ==0){
        dodaj_na_pocetak(&(*g)->sledeci, (*g)->vrednost + (*g)->sledeci->vrednost);
        umetni(&((*g)->sledeci)->sledeci);
    }
    else
        umetni(&(*g)->sledeci);
}

int main(){
    CVOR*g = NULL;
    
    ucitaj_cvor(&g, stdin);
    umetni(&g);
    ispisi_cvor(g, stdout);
    
exit(EXIT_SUCCESS);
}
