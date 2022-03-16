#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define N 81

void greska(void){
    fprintf(stderr,"greska\n");
}

int main(){
    char ime1[N];
    scanf("%s", ime1);
    FILE* izlaz;
    izlaz = fopen(ime1, "w");

    if(izlaz==NULL)
        greska();
    
    char s[N];
    scanf("%s",s);
    for(int i=0;i<strlen(s);i++)
        if(isalpha(s[i]))
            if(s[i]>65 && s[i]<=90)
            fprintf(izlaz, "%c", s[i]+31);
            else if(s[i]>97 && s[i]<=122)
            fprintf(izlaz, "%c", s[i]-33);
            else if(s[i]==65)
            fprintf(izlaz, "z");
            else if(s[i]==97)
            fprintf(izlaz, "Z");
            
fclose(izlaz);
exit(EXIT_SUCCESS);
}
