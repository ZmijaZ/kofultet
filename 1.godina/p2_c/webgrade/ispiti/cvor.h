#ifndef _H_CVOR_
#define _H_CVOR_

#include <stdio.h>
#include <stdlib.h>

typedef struct _cvor{
    int vrednost;
    struct _cvor* sledeci;
}CVOR;

void greska(void);

CVOR*napravi_cvor(int broj);

void dodaj_na_pocetak(CVOR*g, int broj);

void ispisi (CVOR*g, FILE*f);

void dodaj_na_kraj (CVOR**g, int broj);

void ucitaj (CVOR**g, FILE*f);

void oslobodi(CVOR*g);

#endif
