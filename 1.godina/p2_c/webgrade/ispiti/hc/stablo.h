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

void dodaj_cvor(CVOR**koren, int broj);

void ucitaj_stablo(CVOR**koren, FILE*f);

void ispisi_infiksno(CVOR*koren, FILE*f);

void ispisi_prefiksno(CVOR*koren, FILE*f);

void ispisi_postiksno(CVOR*koren, FILE*f);

void oslobodi_stablo(CVOR*koren);


#endif
