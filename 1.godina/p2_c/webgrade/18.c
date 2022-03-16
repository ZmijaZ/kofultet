#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 127

void greska(void){
    fprintf(stderr, "-1");
    exit(EXIT_FAILURE);
}
int main(){
char *rec; FILE* ulaz, *izlaz;
    ulaz = fopen("razno.txt", "r");
    izlaz= fopen("palindromi.txt", "w");
        if(ulaz == NULL || izlaz == NULL)
            greska();
    rec = (char*)malloc(N*sizeof(char));
        if(rec==NULL)
            greska();
    
    while(fscanf(ulaz ,"%s", rec)!=EOF){
        int b=0;
        for(int i=0, j=strlen(rec)-1; i<strlen(rec), j>0; i++, j--)
            if(tolower(rec[i])==tolower(rec[j]))
                b++;
        if(b==strlen(rec)-1)
            fprintf(izlaz ,"%s ",rec);
    }
free(rec);
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}
