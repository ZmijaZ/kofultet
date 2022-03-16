#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct _cvor{
    int vrednost;
    struct _cvor* sledeci;

}CVOR;

void greska(void);

CVOR*napravi_cvor(int broj);

void dodaj_na_pocetak(CVOR** glava, int broj);

void ispisi_listu(CVOR* glava);

void ispisi_listur(CVOR* glava);

void dodaj_na_kraj(CVOR**glava, int broj);

#endif
