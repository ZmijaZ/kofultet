#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void ispis(char*s, FILE*f, int k){
    int i, j, p, n = strlen(s);
    if(k>n)
        greska();
    for(i = 0; i<=n-k; i++){
        for(j = i, p = 0; p<k; j++, p++){
            fprintf(f, "%c", *(s+j));
        }

        fprintf(f, " ");

    }
    fprintf(f, "\n");
}


int main(int argc, char**argv){
    if(argc != 3)
        greska();
    int n;
    sscanf(argv[1], "%d", &n);
        if(n < 1)
            greska();
            
    FILE*ulaz = fopen("podniske.txt", "w");
        if(ulaz == NULL)
            greska();
    
    ispis(argv[2], ulaz, n);
    
fclose(ulaz);
exit(EXIT_SUCCESS);
}
