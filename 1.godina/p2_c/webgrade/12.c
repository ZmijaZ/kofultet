#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 21

void greska (void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){

char* ime1; int* niz;
    ime1 = (char*)malloc(N*sizeof(char));
    niz = (int*)malloc(10*sizeof(int));
        if(ime1==NULL || niz == NULL)
            greska();
    scanf("%s", ime1);
    
FILE *ulaz;
    ulaz = fopen(ime1, "r");
        if(ulaz==NULL)
            greska();

int n = 10;
for(int i=0;i<n;i++)
    niz[i]=0;
char c;
    while(fscanf(ulaz, "%c", &c) !=EOF)
        if(isdigit(c))
            niz[c-'0']++;
int maxi, max=0; 
for(int i=0;i<n;i++)
    if(niz[i]>max){
        maxi=i;
        max = niz[i];
    }
if(max>0)
    printf("%d\n", maxi);
else
    printf("-1\n");
    
fclose(ulaz);
free(ime1);
exit(EXIT_SUCCESS);
}
