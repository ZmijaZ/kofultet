#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 21
#define N 100

void greska (void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int sufiks(char s[], char c[]){
    int p; int b=0; int i,j;
    for( i=strlen(s), j=strlen(c);i>0;i--,j--)
        if(s[i]==c[j])b++;
    
    if(b==strlen(s))p=1;else p=0;
    return p;
}
int prefiks(char s[],char c[]){
    int p; int b=0; int i,j;
    for(i=0, j=0;i<strlen(s);i++,j++)
        if(s[i]==c[j])b++;
        
    if(b==strlen(s))p=1;else p=0;
    return p;
}


int main(){
char s[I]; int n; char c[I];
scanf("%s",s);
scanf("%d",&n);
            if(n>N || n<1)greska();
for(int i=0;i<n;i++){
    scanf("%s",c);
        if(sufiks(s,c)==1 || prefiks(s,c)==1)printf("%s ",c);
}
printf("\n");
exit(EXIT_SUCCESS);
}


