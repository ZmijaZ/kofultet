#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define N 21

typedef struct{
    char imed[N];
    char imeg[N];
    int gold;
    int golg;
}TEKMA;

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void insertion(int*a, int n, TEKMA*b){
    int i, j, pom;
    TEKMA tmp;
    for(i = 1; i<n; i++){
        pom = a[i];
        strcpy(tmp.imed, b[i].imed);
        strcpy(tmp.imeg, b[i].imeg);
        tmp.gold = b[i].gold;
        tmp.golg = b[i].golg;
        
        for(j = i; j>0 && a[j] < a[j-1]; j--){
            a[j-1] = a[j];
            strcpy(b[j-1].imed, b[j].imed);
            strcpy(b[j-1].imeg, b[j].imeg);
            b[j-1].gold = b[j].gold;
            b[j-1].gold = b[j].golg;
        }
        a[j] = pom;
        strcpy(b[j].imed, tmp.imed);
        strcpy(b[j].imeg, tmp.imeg);
        b[j].gold = tmp.gold;
        b[j].golg = tmp.golg;
    }
    return;
}


int main(){
    int n;
    scanf("%d", &n);
        if(n<1)
            greska();
    TEKMA*niz = (TEKMA*)malloc(n*sizeof(TEKMA));
        if(niz == NULL)
            greska();
    
    int*nizg = (int*)malloc(n*sizeof(int));
        if(nizg == NULL)
            greska();
    
    int i;
    for(i = 0; i<n; i++){
        scanf("%s%s%d%d", niz[i].imed, niz[i].imeg, &niz[i].gold, &niz[i].golg);
            if(niz[i].gold < 0 || niz[i].golg < 0)
                greska();
        nizg[i] = abs(niz[i].gold - niz[i].golg);
    }
    
    insertion(nizg, n, niz);
    
    for(i = 0; i<n; i++)
        printf("%s %s %d %d %d\n", niz[i].imed, niz[i].imeg, niz[i].gold, niz[i].golg, nizg[i]);
    
    
free(niz);
free(nizg);
exit(EXIT_SUCCESS);
}
