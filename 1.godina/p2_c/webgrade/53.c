#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

char* sadrzi(char* s, char c){
    if(*s == '\0')
    return NULL;
    
    if(*s == c)
        return s;
    
    sadrzi(s+1, c);
}

int main(){
char* s = (char*)malloc(sizeof(char)); char c;
    if(s == NULL)
        greska();
int alocirano = 1; int i = 0;
while(1){
    if(i == alocirano){
        alocirano++;
        s = (char*)realloc(s, alocirano*sizeof(char));
            if(s == NULL)
                greska();
    }
    if(*(s+i) == '\0')
        break;
    i++;
}
scanf("%s %c", s, &c);

printf("%d\n", *sadrzi(s,c));
free(s);
exit(EXIT_SUCCESS);
}
