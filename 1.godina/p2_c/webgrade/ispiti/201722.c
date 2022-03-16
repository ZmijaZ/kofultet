#include <stdio.h>
#include <stdlib.h>

#define N 21

typedef struct {
    char ime[N];
    char prezime[N];
    float prosek;
}STUDENT;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void insertion(STUDENT*a, int n){
    int i, j;
    
    for(i = 1; i<n; i++){
        float pom = a[i].prosek;
        for(j = i; j>0 && a[j].prosek > a[j-1].prosek; j--)
            a[j-1].prosek = a[j].prosek;
        a[j].prosek = pom;
    }
    return;
}

int main(){
    float prosek;
    scanf("%f", &prosek);
        if(prosek > 10 || prosek < 6)
            greska();
    int n, i;
    scanf("%d", &n);
        if(n <= 0)
            greska();
    
    STUDENT*niz = (STUDENT*)malloc(sizeof(STUDENT));
        if(niz == NULL)
            greska();
    
    for(i = 0; i<n; i++){
        scanf("%s%s%f", niz[i].prezime, niz[i].ime, &niz[i].prosek);
            if(niz[i].prosek > 10 || niz[i].prosek < 6)
                greska();
    }
    insertion(niz, n);
    for(i = 0; i<n; i++)
        printf("%s %s %.2f\n", niz[i].prezime, niz[i].ime, niz[i].prosek);

free(niz);
exit(EXIT_SUCCESS);
}
