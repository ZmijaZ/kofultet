#include "stabla.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
    
    return;
}

CVOR*napravi_cvor(int vrednost){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
    novi->vrednost = vrednost;
    novi->levi = NULL;
    novi->desni = NULL;
    
    return novi;
}

void dodaj_cvor(CVOR**koren, int vrednost){
    if(*koren == NULL){
        CVOR*novi = napravi_cvor(vrednost);
        *koren = novi;
        return;
    }
    if(vrednost <= (*koren)->vrednost)
        dodaj_cvor(&(*koren)->levi, vrednost);
    else
        dodaj_cvor(&(*koren)->desni, vrednost);
}

void ucitaj_stablo(CVOR**koren, FILE*f){
    int broj;
    while(fscanf(f, "%d", &broj)!=EOF)
        dodaj_cvor(koren, broj);
    
}

void ispisi_stablo_infiksno(CVOR*koren){
    if(koren == NULL)
        return;
    ispisi_stablo_infiksno(koren->levi);
    printf("%d ", koren->vrednost);
    ispisi_stablo_infiksno(koren->desni);
}

void ispisi_stablo_prefiksno(CVOR*koren){
    if(koren == NULL)
        return;
    printf("%d ", koren->vrednost);
    ispisi_stablo_prefiksno(koren->levi);
    ispisi_stablo_prefiksno(koren->desni);
    
}

void ispisi_stablo_postfiksno(CVOR*koren){
    if(koren == NULL)
        return;
    
    ispisi_stablo_postfiksno(koren->levi);
    ispisi_stablo_postfiksno(koren->desni);
    printf("%d ", koren->vrednost);
}

void ispisi(CVOR* koren, FILE*f){
    if(koren == NULL)
        return;
    if(f == NULL)
        greska();
    ispisi(koren->levi, f);
    fprintf(f, "%d ", koren->vrednost);
    ispisi(koren->desni, f);
    
}

void oslobodi(CVOR*koren){
    if(koren){
        oslobodi(koren->levi);
        oslobodi(koren->desni);
        free(koren);
    }
    else return;
    
}
