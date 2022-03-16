#include <stdio.h>
#include <stdlib.h>

#define BROJ_CIFARA 10

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int x, x_original, cifra, i;
  
  /* Svaki element niza brojaci predstavlja brojac za jednu od
    cifara: brojac[0] predstavlja broj nula u zapisu broja x
    brojac[1] predstavlja broj jedinica u zapisu broja x ...
    brojac[9] predstavlja broj devetki u zapisu broja x.
    Brojace je potrebno inicijalizovati na pocetku. */
  /* I nacin: */
  int brojaci[BROJ_CIFARA];
  for(i=0; i<BROJ_CIFARA; i++)
    brojaci[i] = 0;

  /* II nacin: Inicijalizacija pri samoj deklaraciji. 
    Na ovaj nacin su svi elementi niza brojaci inicijalizovani na
    nule. 
    int brojaci[BROJ_CIFARA] = {0}; */
  
  /* Ucitavanje celog broja. */
  printf("Unesite ceo broj:\n");
  scanf("%d", &x);

  /* Cuvanje pocetne vrednosti zbog finalnog ispisa. */
  x_original = x;
  x = abs(x);

  /* Obrada cifara. */
  do {
    /* Izdvajanje krajnje desne cifre. */
    cifra = x % 10;

    /* Uvecavanje broja pojavljivanja izdvojene cifre. */
    brojaci[cifra]++;

    /* Prelazak na analizu sledece cifre. */
    x /= 10;
  } while (x);

  /* Ispis informacija o ciframa koje se nalaze u zapisu broja x. */
  for (i = 0; i < BROJ_CIFARA; i++)
    if (brojaci[i]) {
      printf("U zapisu broja %d, cifra %d se pojaviljuje %d puta\n",
             x_original, i, brojaci[i]);
    }

  exit(EXIT_SUCCESS);
}
