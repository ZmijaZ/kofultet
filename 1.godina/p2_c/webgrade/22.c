#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv){
    if(argc!=2)
        greska();
    
    FILE * ulaz = fopen(argv[1], "r");
        if(ulaz==NULL)
            greska();
            
    char c; int b1=0; int b2=0; int p;
    while(fscanf(ulaz, "%c", &c)!=EOF){
        if(c=='(')
            b1++;
        if(c==')')
            b2++;
        if(b2>b1){
            p=0;
            break;
        }
    }

    if(p==0 || b1!=b2)
        printf("nisu\n");
    else 
        printf("jesu\n");
    
fclose(ulaz);
exit(EXIT_SUCCESS);
}
