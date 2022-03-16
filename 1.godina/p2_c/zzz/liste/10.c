#include "cvor.h"

int veci_od(CVOR*glava, int broj){
    if(glava == NULL)
        return 0;
    if(glava->vrednost > broj)
        return veci_od(glava->sledeci, broj)+1;
    else
        return veci_od(glava->sledeci, broj);
    
}

CVOR* dodaj_element(CVOR*glava, int x){
    if(glava == NULL)
        return napravi_cvor(x);
    if(glava->vrednost > x){
        CVOR*novi = napravi_cvor(x);
        novi->sledeci = glava;
        return novi;
    }
    else
        glava->sledeci = dodaj_element(glava->sledeci, x);
    
}

int main(){
   CVOR*g = NULL;
   CVOR*g1 = NULL;
  
   
   ucitaj_listu(&g, stdin);
   ucitaj_listu(&g1,stdin);
   

   ispisi_listu(g);
   ispisi_listu(g1);
}

