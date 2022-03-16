#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void mala(char*s){
    int i; int n = strlen(s);
    for(i = 0; i<n; i++)
        *(s+i) = tolower(*(s+i));
    return;
}

void velika(char*s){
    int i; int n = strlen(s);
    for(i = 0; i<n; i++)
        *(s+i) = toupper(*(s+i));
    return;
}

void srednja(char*s){
    int i; int n = strlen(s);
    for(i = 0; i<n; i++)
        if (islower(*(s+i)) )
            *(s+i) = toupper(*(s+i));
        else if(isupper(*(s+i)) )
            *(s+i) = tolower(*(s+i));
    return;
}

int main(int argc, char**argv){

    if(argc!=3)
        greska();
    if(strcmp(argv[1], "-m") == 0)
        mala(argv[2]);
    else if(strcmp(argv[1], "-v") == 0)
        velika(argv[2]);
    else if(strcmp(argv[1], "-mv") == 0)
        srednja(argv[2]);
    else
        greska();
    
printf("%s\n", argv[2]);
exit(EXIT_SUCCESS);
}
