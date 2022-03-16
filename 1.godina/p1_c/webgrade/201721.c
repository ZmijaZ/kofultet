#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 5

int main(){
char op,i; int b; int b1=0; int p=1;
scanf("%c",&op);
char s[N];
scanf("%s",s);

switch(op){
case 'C' :
    for(i=0;s[i]!='\0';i++){
        if(isdigit(s[i])){
        b1++; p*=(s[i]-'0');} }
        if (b1==0)p=0;
            printf("%d\n",p);
            exit(EXIT_SUCCESS);
case 'V' :
    for(i=0;s[i]!='\0';i++){
        if(isupper(s[i]))b++;}
        printf("%d\n",b);
        exit(EXIT_SUCCESS);

default:
    printf("-1\n");
    exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
