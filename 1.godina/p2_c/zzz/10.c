#include "cvor.h"

int main(){
    CVOR*g = NULL;

    int n, x, y, z;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        scanf("%d", &x);
        dodaj_na_pocetak(&g, x);
    }
    
    scanf("%d", &y);
    dodaj_na_pocetak(&g, y);
    
    scanf("%d", &z);
    dodaj_na_kraj(&g, z);
    
    ispisi_listu(g);
    
    
printf("\n");
exit(EXIT_SUCCESS);
}
