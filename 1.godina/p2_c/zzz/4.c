#include <stdio.h>
#include <stdlib.h>
#include "polinom.h"

int main(){

int n, m;

int*niz1 = unos(&n);
    if(niz1 == NULL)
        greska();
int*niz2 = unos(&m);
    if(niz2 == NULL)
        greska();
int*niz3;   
    
int res = suma_polinoma(niz1, n, niz2, m, &niz3);
ispisi(niz3, res);

exit(EXIT_SUCCESS);
}
