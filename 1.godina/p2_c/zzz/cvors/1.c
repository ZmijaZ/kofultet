#include "cvor.h"

CVOR*naizmenicno(CVOR*g1, CVOR*g2){
    if(g1 == NULL)
        return g2;
    if(g2 == NULL)
        return g1;
    
    g1->sledeci = naizmenicno(g2, g1->sledeci);
    
    return g1;
}

int uListi(CVOR*g, int x){
    while(g != NULL){
        if(g->vrednost == x)
            return 1;
        g = g->sledeci;
    }
    return 0;
}

int zbir(CVOR*g1, CVOR*g2){
    int suma = 0;
    while(g1 != NULL){
        if(!uListi(g2, g1->vrednost))
           suma+=g1->vrednost;
        g1 = g1->sledeci;
    }
    return suma;
}

void umetni(CVOR*g){
    if(g == NULL)
        return;
    if(g->sledeci == NULL)
        return;
    
    int razlika = g->vrednost - g->sledeci->vrednost;
    
    CVOR*novi = napravi_cvor(razlika);
    CVOR*tmp = g->sledeci;
    
    g->sledeci = novi;
    novi->sledeci = tmp;

    umetni(novi->sledeci);

    return;
}

CVOR*izbaci(CVOR*g1, CVOR*g2){
    
    CVOR*pocetak = g1;
    
    while(g1->sledeci!=NULL){
        if(uListi(g2, g1->sledeci->vrednost) == 1){
            CVOR*pom = g1->sledeci;
            g1->sledeci = g1->sledeci->sledeci;
            free(pom);
        }
        g1 = g1->sledeci;
    }
    
    
    g1 = pocetak;
    
    if(uListi(g2, g1->vrednost) == 1){
        CVOR*pom = g1;
        g1 = g1->sledeci;
        free(pom);
    }
    return g1;
}

int main(){
    CVOR*g1 = NULL;
    CVOR*g2 = NULL;
    CVOR*g3 = NULL;
    
    FILE*ulaz1 = fopen("ulaz1.txt", "r");
    FILE*ulaz2 = fopen("ulaz2.txt", "r");
    
    
    ucitaj_listu(&g1, ulaz1);
    ucitaj_listu(&g2, ulaz2);
    
    g3 = izbaci(g1, g2);
    
    ispisi_listu(g3, stdout);

exit(EXIT_SUCCESS);
}
