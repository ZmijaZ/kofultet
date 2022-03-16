#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int unesiSkup(char **s, FILE*f){
    int i=0; int br = 0; int j;
    while(fscanf(f, "%s", s[i])!= EOF){
        int rec = strlen(s[i]);
        for(j=0; j<rec ;j++){
        if(s[i][j] == '\n')
            break;
        if( !(isalpha(&s[i]) || isdigit(&s[i])) )
            break;
        br++;
        }
        if(j<rec-1)
            break;
        i++;
    }
    return br;
}

void prebroj(char* s, int *br_slova, int *br_cifara){
    int rec = strlen(s);
    for(int i = 0; i<rec; i++){
        if(isdigit(s[i]))
            (*br_cifara)++;
        if(isalpha(s[i]))
            (*br_slova)++;
    }
    printf("broj slova: %d\nbroj cifara: %d\n",*br_slova, *br_cifara);
}

int main(int argc, char **argv){
    if(argc!=2)
        greska();
        
    FILE* ulaz = fopen(argv[1], "r");
        if(ulaz == NULL)
            greska();

    char **s;
    s = (char*)malloc(sizeof(char*));
        if(s == NULL)
            greska();
    int ucitano = 1; int i=0;
    
    while(1){
        
        if(i==ucitano){
            ucitano++;
            s = realloc(s, ucitano*sizeof(char*));
        }
        
        if(s == EOF)
            break;
        i++;
    }
    for(i=0; i<strlen(s); i++){
        s[i] = (char*)malloc(sizeof(char));
        int ucitanoi = 1; int j=0;
        while(1){
          
            if(j==ucitanoi){
                ucitanoi++;
                s[i] = realloc(s[i], ucitano*sizeof(char));
                
            }
            if(s[i] == ' ' || s[i] == '\n' || s[i] == EOF)
                break;
            j++;
        }
    }    
free(s);
fclose(ulaz);
exit(EXIT_SUCCESS);
}


