#ifndef _H_LISTA_
#define _H_LISTA_

#include <stdlib.h>
#include <stdio.h>

typedef struct _cvor{
    int vrednost;
    struct _cvor*sledeci;
}CVOR;

void greska(void);

CVOR*napravi_cvor(int broj);

void dodaj_na_pocetak(CVOR**g, int broj);

void ucitaj_cvor(CVOR**g, FILE*f);

void ispisi_cvor(CVOR*g, FILE*f);

void dodaj_na_kraj(CVOR**g, int broj);

void oslobodi_cvor(CVOR*g);

#endif
