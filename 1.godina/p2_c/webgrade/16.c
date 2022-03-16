#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 128

void greska(void){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int main(){
char* ime1; char* rec; char* pomoc;
    ime1 = (char*)malloc(N*sizeof(char));
    rec = (char*)malloc(N*sizeof(char));
    pomoc = (char*)malloc(N*sizeof(char));
        if(ime1 == NULL || rec == NULL || pomoc == NULL)
            greska();
int k; int i,j;
scanf("%s %d", ime1, &k);
    if(k<0)
        greska();
FILE* ulaz, *izlaz;
    ulaz = fopen(ime1, "r");
    izlaz = fopen("rotirano.txt", "w");
        if(ulaz == NULL || izlaz == NULL)
            greska();

    while(fscanf(ulaz, "%s", rec)!=EOF){
     
        if(k<strlen(rec)){
            for (i=k, j=0; i<strlen(rec); i++, j++)
                pomoc[j]=rec[i];
            for(i=0; i<k; i++,j++)
                pomoc[j]=rec[i];
            pomoc[strlen(rec)]='\0';
    }
        else if(k>strlen(rec)){
            for(i=k%strlen(rec), j=0; i<strlen(rec); i++, j++)
                pomoc[j]=rec[i];
            for(i=0; i<k%strlen(rec); i++, j++)
                pomoc[j]=rec[i];
            pomoc[strlen(rec)]='\0';
        }
        else
            strcpy(pomoc, rec);
    
    fprintf(izlaz, "%s ", pomoc);
}

free(rec);
free(pomoc);
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}
           
           
