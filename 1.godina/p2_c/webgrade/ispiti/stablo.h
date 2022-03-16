#ifndef _STABLO_H_
#define _STABLO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _cvor{
    int vrednost;
    struct _cvor*levi;
    struct _cvor*desni;
}CVOR;


void greska(void);

CVOR*napravi_cvor(int broj);

void dodaj_u_stablo(CVOR**g, int broj);

void ucitaj(CVOR**g, FILE*f);

void ispisi_infiksno(CVOR*g, FILE*f);

void ispisi_prefiksno(CVOR*g, FILE*f);

void ispisi_postfiksno(CVOR*g, FILE*f);

void oslobodi(CVOR*g);

#endif
