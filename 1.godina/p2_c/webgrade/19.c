#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 64

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int proveri(char* s, char* c){
    int b=0, p=0;
    for(int i=0; i<strlen(s); i++){
        if(s[i]==c[0])
            for(int j=i+1,k=1;k<strlen(c);j++,k++)
                if(s[j]==c[k])
                    b++;
        if(b==strlen(c)-1){
            p++;
            b=0;
        }
    }
    return p;
}

int main(){
char *ime1, *ime2, *rec, *rec1;
    ime1 = (char*)malloc(N*sizeof(char));
    ime2 = (char*)malloc(N*sizeof(char));
    rec = (char*)malloc(N*sizeof(char));
    rec1 = (char*)malloc(N*sizeof(char));
        if(ime1 == NULL || ime2 == NULL || rec1 == NULL || rec == NULL)
            greska();

int k;
    scanf("%s %s %d", ime1, ime2, &k);
    
FILE* ulaz, *izlaz;
    ulaz = fopen(ime1, "r");
    izlaz = fopen(ime2, "w");
        if(ulaz == NULL || izlaz == NULL || k<1)
            greska();
    fscanf(ulaz, "%s", rec1);
int brojac=0, bl=1; char c;
    while(fscanf(ulaz, "%s", rec) !=EOF){
        if(proveri(rec, rec1))
            brojac+=proveri(rec, rec1);
        fscanf(ulaz, "%c", &c);
        if(c == '\n'){
            if(brojac >= k)
                fprintf(izlaz, "%d:%d\n", brojac, bl); 
            brojac = 0;
            bl++;
        }
    
    }

free(rec);
free(ime1);
free(ime2);
free(rec1);
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}

