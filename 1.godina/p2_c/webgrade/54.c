#include <stdio.h>
#include <stdlib.h>

#define N 64

int poredi(char* s1, char* s2){
    if(*s1 == '\0' && *s2 == '\0')
        return 0;
    if(*s1 != *s2)
        return 1;
        
    poredi(s1+1, s2+1);
}

int main(){
    char s1[N];
    char s2[N];
    while(scanf("%s%s", s1, s2) != EOF){
        printf("%d\n", poredi(s1, s2));
    }
exit(EXIT_SUCCESS);
}
