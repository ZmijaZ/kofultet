#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void greska(void){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

char* alociraj(int n){
    char*a = (char*)malloc(n*sizeof(char));
        if(a == NULL)
            greska();
    return a;
} 

int main(){
    
char*ime1 = alociraj(21);
    if(ime1 == NULL)
        greska();
scanf("%s", ime1);

char*ime2 = alociraj(21);
    if(ime2 == NULL)
        greska();
scanf("%s", ime2);

FILE*ulaz = fopen(ime1, "r");
FILE*izlaz = fopen(ime2, "w");
    if(ulaz == NULL || izlaz == NULL)
        greska();

 int azbir = 0;

char*s = (char*)malloc(201*sizeof(char));
    if(s == NULL)
        greska();
    
while(fscanf(ulaz, "%s", s) != EOF){
    for(int i =0; i<(strlen(s)); i++)
        azbir+=s[i];
    printf("%d ", azbir);
    azbir = 0;
}

printf("\n");
exit(EXIT_SUCCESS);
}
