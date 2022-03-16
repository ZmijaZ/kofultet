#include "stablo.h"

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

CVOR*napravi_cvor(int broj){
    CVOR*novi = (CVOR*)malloc(sizeof(CVOR));
        if(novi == NULL)
            greska();
            
    novi->vrednost = broj;
    novi->levi = NULL;
    novi->desni = NULL;
    
    return novi;
}

void dodaj_cvor(CVOR**koren, int broj){
    if(*koren == NULL){
        *koren = napravi_cvor(broj);
        return;
    }
    if((*koren)->vrednost > broj)
        dodaj_cvor(&(*koren)->levi, broj);
    else
        dodaj_cvor(&(*koren)->desni, broj);
        
}

void ucitaj_stablo(CVOR**koren, FILE*f){
    int x;
    while(fscanf(f, "%d", &x) !=EOF)
        dodaj_cvor(koren, x);
}

void ispisi_infiksno(CVOR*koren, FILE*f){
    if(koren !=NULL){
        ispisi_infiksno(koren->levi, f);
        fprintf(f, "%d ", koren->vrednost);
        ispisi_infiksno(koren->desni, f);
    }
}

void ispisi_prefiksno(CVOR*koren, FILE*f){
    if(koren !=NULL){
        fprintf(f, "%d ", koren->vrednost);
        ispisi_prefiksno(koren->levi, f);
        ispisi_prefiksno(koren->desni, f);
    }
}

void ispisi_postiksno(CVOR*koren, FILE*f){
    if(koren !=NULL){
        ispisi_prefiksno(koren->levi, f);
        ispisi_prefiksno(koren->desni, f);
        fprintf(f, "%d ", koren->vrednost);
    }
}

void oslobodi_stablo(CVOR*koren){
    if(koren){
        oslobodi_stablo(koren->levi);
        oslobodi_stablo(koren->desni);
        free(koren);
    }
}
