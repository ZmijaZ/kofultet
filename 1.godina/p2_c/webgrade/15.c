#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    FILE* ulaz, *izlaz;
    ulaz = fopen("plain.txt", "r");
    izlaz = fopen("sifra.txt", "w");
    if(ulaz==NULL || izlaz ==NULL)
        greska();
    
    char c;
    while(fscanf(ulaz, "%c", &c)!=EOF){
        if(c=='a')
            fprintf(izlaz, "Z");
        else if(c=='A')
            fprintf(izlaz, "z");
        else if(isupper(c))
            fprintf(izlaz, "%c", c+31);
        else if(islower(c))
            fprintf(izlaz, "%c", c-33);
        else 
            fprintf(izlaz, "%c", c);
    }

        
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}
