#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int veci_od_proseka(){
    int *niz = (int*)malloc(sizeof(int));
        if(niz == NULL)
            greska();
    int alocirano = 1; int i = 0;
    while(1){
        if(alocirano == i){
            alocirano++;
            niz = (int*)realloc(niz, alocirano*sizeof(int));
                if(niz == NULL)
                    greska();
        }
        scanf("%d", niz+i);
        if(*(niz+i) == 0)
            break;
        i++;
    }
    
    int j; float zbir = 0; int br = 0;
    for(j = 0; j<i; j++)
        zbir+=(*(niz+j));
    zbir/=i;
    
    for(j = 0; j<i; j++)
        if(*(niz+j) > zbir)
            br++;
        
    return br;
}

int main(){
printf("%d\n", veci_od_proseka());

exit(EXIT_SUCCESS);
}
