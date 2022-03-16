#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(void){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    int x;
    int y;
    int z;

}VEKTOR;

int main(){
    FILE* ulaz; int n,i; VEKTOR *niz;
    ulaz = fopen("vektori.txt", "r");
        if(ulaz==NULL)
            greska();
    
    fscanf(ulaz,"%d",&n);
        if(n<=0)
            greska();
            
    niz = malloc(n*sizeof(VEKTOR));        
        if(niz==NULL)
            greska();
            
    int max = 0; int d; int x,y,z;
    for(i=0;i<n;i++){
        fscanf(ulaz, "%d %d %d", &niz[i].x, &niz[i].y, &niz[i].z);
        d=sqrt(pow(niz[i].x,2)+pow(niz[i].y,2)+pow(niz[i].z,2));
        if(d>max){
        max=d;
        x=niz[i].x;
        y=niz[i].y;
        z=niz[i].z;
        }
}
printf("%d %d %d\n", x,y,z);
fclose(ulaz);
free(niz);
exit(EXIT_SUCCESS);
}
