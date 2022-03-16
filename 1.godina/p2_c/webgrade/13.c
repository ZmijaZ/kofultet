#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 64

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int broj_cifara(int n){
    int b=0;
    n=abs(n);
    while(n>0){
        b++;
        n/=10;
    }
    return b;
}

int main(){
    int k; char ime1[N];
    scanf("%d %s", &k, ime1);
        if(k<=0)
            greska();
    FILE* ulaz = fopen(ime1,"r");
        if(ulaz==NULL)
            greska();
    
    int n; int n1; int b=0;
    fscanf(ulaz, "%d", &n);
        if(n<0)
            greska();
            
    for(int i=0;i<n;i++){
        fscanf(ulaz,"%d", &n1);
        if(broj_cifara(n1)==k)
            b++;
    }

printf("%d\n", b);    
fclose(ulaz);
exit(EXIT_SUCCESS);
}
