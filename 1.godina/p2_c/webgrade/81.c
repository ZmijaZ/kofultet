#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double Ax;
    double Ay;
    double Bx;
    double By;
}DUZ;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void selection(double*a, int n, DUZ*niz){
    int i, j, max;
    double pom;
    DUZ tmp;
    for(i = 0; i<n; i++){
        max = i;
        for(j = i+1; j<n; j++)
            if(a[j] > a[max])
                max = j;
        pom = a[max];
        a[max] = a[i];
        a[i] = pom;
        
        tmp.Ax = niz[max].Ax;
        niz[max].Ax = niz[i].Ax;
        niz[i].Ax = tmp.Ax;
        
        tmp.Ay = niz[max].Ay;
        niz[max].Ay = niz[i].Ay;
        niz[i].Ay = tmp.Ay;
        
        tmp.Bx = niz[max].Bx;
        niz[max].Bx = niz[i].Bx;
        niz[i].Bx = tmp.Bx;
        
        tmp.By = niz[max].By;
        niz[max].By = niz[i].By;
        niz[i].By = tmp.By;
    }
    return;
}

int main(){
    FILE*ulaz = fopen("duzi.txt", "r");
        if(ulaz == NULL)
            greska();

    int n, i;
    fscanf(ulaz, "%d", &n);
    
    DUZ*niz = (DUZ*)malloc(n*sizeof(DUZ));
        if(niz == NULL)
            greska();
    double*duzi = (double*)malloc(n*sizeof(double));
        if(duzi == NULL)
            greska();
        
    for(i = 0; i<n; i++){
        fscanf(ulaz, "%lf%lf%lf%lf", &niz[i].Ax, &niz[i].Ay, &niz[i].Bx, &niz[i].By);
        duzi[i] = sqrtf(  pow(niz[i].Bx-niz[i].Ax, 2) + pow(niz[i].By- niz[i].Ay, 2) );
    }
    
    selection(duzi, n, niz);
    
    for(i = 0; i<n; i++)
        printf("%.2lf %.2lf %.2lf %.2lf %.2lf\n", niz[i].Ax, niz[i].Ay, niz[i].Bx, niz[i].By, duzi[i]);
    
fclose(ulaz);
free(niz);
free(duzi);
exit(EXIT_SUCCESS);
}
