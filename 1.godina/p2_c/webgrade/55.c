#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* podniska(char* s1, char* s2){
    
}

int main(){

char *s, *t;
s = (char*)malloc(sizeof(char));
    if(s == NULL)
        greska();
t = (char*)malloc(sizeof(char));
    if(t == NULL)
        greska();
        
int alociranos = 1, alociranot = 1, i = 0, j = 0;
while(1){
    if(i==alociranos){
        alociranos++;
        s = (char*)realloc(s, alociranos*sizeof(char));
            if(s == NULL)
                greska();
    }
    if(*(s+i) == '\0')
        break;
    i++;
}
while(1){
    if(j==alociranot){
        alociranot++;
        t = (char*)realloc(t, alociranot*sizeof(char));
            if(t == NULL)
                greska();
    }
    if(*(t+i) == '\0')
        break;
    j++;
}
scanf("%s %s", s, t);



exit(EXIT_SUCCESS);
}
