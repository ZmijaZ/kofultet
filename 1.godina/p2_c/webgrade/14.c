#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define N 64

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    char ime1[N]; char ime2[N];
    scanf("%s %s", ime1, ime2);
    FILE* ulaz,*izlaz;
    ulaz = fopen(ime1, "r");
    izlaz = fopen(ime2, "w");
        if(ulaz==NULL || izlaz == NULL)
            greska();
            
    char c;
    while(fscanf(ulaz, "%c", &c)!=EOF){
        if(isdigit(c))
            fprintf(izlaz, "0"); 
        else if(isalpha(c))
            fprintf(izlaz, "1");
        else if(isgraph(c))
            fprintf(izlaz, "2");
    }
        
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}
