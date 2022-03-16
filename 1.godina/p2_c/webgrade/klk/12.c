#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
FILE* ulaz, *izlaz1, *izlaz2;
ulaz = fopen("r.txt", "r");
izlaz1 = fopen("b.txt", "w");
izlaz2 = fopen("o.txt", "w");
    if (ulaz == NULL || izlaz1 == NULL || izlaz2 == NULL)
        greska();
int n;
fscanf(ulaz, "%d", &n);
    if(n<0)
        greska();
char *s = (char*)malloc(sizeof(char));
    if(s==NULL)
        greska();
int alocirano = 1, k = 0;
while(1){
    if(k==alocirano){
        alocirano++;
        s = (char*)realloc(s, alocirano*sizeof(char));
        
        if(*(s+k) == '\0')
            break;
    }
    k++;
}

for(int i=0; i<n; i++){
    fscanf(ulaz, "%s", s);
    int br = 0;
    int duzina_reci = strlen(s);
        for(int j=0; j<duzina_reci; j++)
            if(isdigit(*(s+j)))
                br++;
    if(br == duzina_reci)
        fprintf(izlaz1, "%s ", s);
    else
        fprintf(izlaz2, "%s ", s);
        
}
free(s);
fclose(ulaz);
fclose(izlaz1);
fclose(izlaz2);
exit(EXIT_SUCCESS);
}
