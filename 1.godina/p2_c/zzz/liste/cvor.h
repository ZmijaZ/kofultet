#ifndef _H_LISTA_
#define _H_LISTA_

#include <stdio.h>
#include <stdlib.h>


typedef struct _cvor{
    int vrednost;
    struct _cvor*sledeci;

}CVOR;

void greska(void);

CVOR* napravi_cvor(int broj);
   
void dodaj_na_pocetak(CVOR** glava, int broj);

void ispisi_listu(CVOR* glava);

void dodaj_na_kraj(CVOR** glava, int broj);

void oslobodi_listu(CVOR* glava);

void ucitaj_listu(CVOR** glava, FILE*f);

#endif
