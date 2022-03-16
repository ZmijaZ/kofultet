#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define N 6

int main(){
char s[N];
char op;
int i,zbir=0,brojac=0;
scanf("%c",&op);

switch (op){
    case 'M':
        scanf("%s",s);
        for (i=0;s[i]!='\0';i++){
            if(islower(s[i]))brojac++;}
        printf("%d\n",brojac);
            exit(EXIT_SUCCESS);
    case 'C':
        scanf("%s",s);
        for (i=0;s[i]!='\0';i++){
            if(isdigit(s[i]))zbir+=s[i]-'0';}
            printf("%d\n",zbir);
            exit(EXIT_SUCCESS);
    default:
        printf("-1\n");
        exit(EXIT_FAILURE);
        }



}
