#ifndef _H_STABLO
#define _H_STABLO

#include <stdio.h>
#include <stdlib.h>

typedef struct _cvor{
    int vrednost;
    struct _cvor *levi;
    struct _cvor *desni;
}CVOR;

void greska(void);

CVOR*napravi_cvor(int vrednost);

void dodaj_cvor(CVOR**koren, int vrednost);

void ucitaj_stablo(CVOR**koren, FILE*f);

void ispisi_stablo_infiksno(CVOR*koren);

void ispisi_stablo_prefiksno(CVOR*koren);

void ispisi_stablo_postfiksno(CVOR*koren);

void ispisi(CVOR* koren, FILE*f);

void oslobodi(CVOR*koren);

#endif
