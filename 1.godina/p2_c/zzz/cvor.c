#include "cvor.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
}

CVOR*napravi_cvor(int broj){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
    novi->vrednost = broj;
    novi->sledeci = NULL;
    
    return novi;

}

void dodaj_na_pocetak(CVOR** glava, int broj){
    CVOR*novi = napravi_cvor(broj);
    
    novi->sledeci = *glava;
    
    *glava = novi;
}

void ispisi_listu(CVOR* glava){
    printf("[");
    while(glava != NULL){
        printf("%d", glava->vrednost);
        if(glava->sledeci)
            printf(", ");
        glava = glava->sledeci;
    }
    printf("]\n");
}

void ispisi_listur(CVOR* glava){
    if(glava == NULL){
        printf("[");
        return;
    }
        
    printf("%d ", glava->vrednost);
    
    ispisi_listur(glava->sledeci);
    
}

void dodaj_na_kraj(CVOR**glava, int broj){
    if(*glava == NULL){
        CVOR* novi = napravi_cvor(broj);
        *glava = novi;
        return;
    }
    
    dodaj_na_kraj(&(*glava)->sledeci, broj);
    
}


