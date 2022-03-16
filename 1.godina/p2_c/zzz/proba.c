#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

int azbir = 0;

char s[51];
while(scanf("%s", s) != EOF){
    for(int i =0; i<(strlen(s)); i++)
        azbir+=s[i];
    printf("%d ",azbir);
    azbir = 0;
}
printf("\n");
exit(EXIT_SUCCESS);
}
