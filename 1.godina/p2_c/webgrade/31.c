#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int imenilac;
    int brojilac;
}RAZLOMAK;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void opcijax(FILE*f, RAZLOMAK*niz, int n){
    int znak = 0, i; 
    for(i = 0; i<n; i++){
        if( (niz[i].brojilac < 0 && niz[i].imenilac < 0)
            ||(niz[i].brojilac > 0 && niz[i].imenilac > 0) )
        znak = 1;
        else if( (niz[i].brojilac < 0 && niz[i].imenilac > 0)
            ||(niz[i].brojilac > 0 && niz[i].imenilac < 0) ) 
        znak = -1;
        
        fprintf(f, "%d/%d\n", znak*abs(niz[i].imenilac),
                abs(niz[i].brojilac) );
    }
    
    return;
}

void opcijay(FILE*f, RAZLOMAK*niz, int n){
    int i; double broj;
    for(i = 0; i<n; i++){
        broj = (double)(niz[i].imenilac)/(double)niz[i].brojilac;
        fprintf(f, "%g\n", broj);
    }
    
    return;
}

void opcijaxy(FILE*f, RAZLOMAK*niz, int n){
    int i, znak; double broj;
    for(i = 0; i<n; i++){
        if( (niz[i].brojilac < 0 && niz[i].imenilac < 0)
            ||(niz[i].brojilac > 0 && niz[i].imenilac > 0) )
        znak = 1;
        else if( (niz[i].brojilac < 0 && niz[i].imenilac > 0)
            ||(niz[i].brojilac > 0 && niz[i].imenilac < 0) ) 
        znak = -1;
        
        broj = (double)(niz[i].imenilac)/(double)niz[i].brojilac;
        
        fprintf(f, "%d/%d %g\n", znak*abs(niz[i].imenilac),
                abs(niz[i].brojilac), broj );
        
    }
    
}

int main(int argc, char**argv){
    if (argc!=4)
        greska();
        
    FILE*ulaz = fopen(argv[1], "r");
    FILE*izlaz = fopen(argv[2], "w");
        if(ulaz == NULL || izlaz == NULL)
            greska();
    
    int n;
    fscanf(ulaz, "%d", &n);
        if(n < 1)
            greska();
    
    RAZLOMAK *niz = (RAZLOMAK*)malloc(n*sizeof(RAZLOMAK));
        if(niz == NULL)
            greska();
    
    for(int i = 0; i<n; i++)
        fscanf(ulaz, "%d/%d", &niz[i].brojilac, &niz[i].imenilac);
   
   
        

    if(strcmp(argv[3], "-x") == 0 )
        opcijax(izlaz, niz, n);
    else if(strcmp(argv[3], "-y") == 0)
        opcijay(izlaz, niz, n);
    else if(strcmp(argv[3], "-xy") == 0 ||
        strcmp(argv[3], "-yx") == 0)
        opcijaxy(izlaz, niz, n);
    else
        greska();

fclose(ulaz);
fclose(izlaz);
free(niz);
exit(EXIT_SUCCESS);
}
