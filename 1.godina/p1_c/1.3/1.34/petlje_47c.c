/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Ispis trazene tablice. */
  for (i = 1; i <= n; i++) {
    for (j = 0; j < n; j++)
      if ((j + i) % n == 0)
        printf("%3d", n);
      else
        printf("%3d", (j + i) % n);

    printf("\n");
  }

  return 0;
}
