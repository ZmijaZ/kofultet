#include <stdio.h>
#include <stdlib.h>

#define N 21

void greska(){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    char ime1[N], ime2[N]; int i=0;
    scanf("%s %s", ime1, ime2);
    FILE *ulaz,*izlaz;
    ulaz = fopen(ime1,"r");
    izlaz = fopen(ime2,"w");
        if(ulaz==NULL || izlaz==NULL)
            greska();
    char c;
    while(fscanf(ulaz, "%c", &c)!=EOF){
        if(i%2==0)
            fprintf(izlaz, "%c", c);
        i++;
    }
    
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}
