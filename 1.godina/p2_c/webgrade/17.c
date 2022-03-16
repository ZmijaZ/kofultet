#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 256
#define USLOV 1000

void greska(void){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
FILE* ulaz,*izlaz;
    ulaz = fopen("ulaz.txt", "r");
    izlaz = fopen("izlaz.txt", "w");
        if(ulaz ==NULL || izlaz ==NULL)
            greska();
char *rec;
    rec = (char*)malloc(N*sizeof(char));
        if(rec==NULL)
            greska();

while(fscanf(ulaz, "%s", rec)!=EOF){
    int zbir =0;
    for(int i=0; i<strlen(rec);i++)
        zbir+=rec[i];
    if(zbir>USLOV)
    fprintf(izlaz, "%s ", rec);
}


fclose(ulaz);
fclose(izlaz);
free(rec);
exit(EXIT_SUCCESS);
}
