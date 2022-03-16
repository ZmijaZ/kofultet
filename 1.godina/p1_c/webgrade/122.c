#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int b, char* s[]){
    int b1=0,B1=0; int i,j;
    if (b==1){printf("-1\n");exit(EXIT_FAILURE);}
    for(i=1;i<b;i++){
        for(j=0;s[i][j];j++){
            if(isupper(s[i][j]))B1++;
            else if(islower(s[i][j]))b1++;
        }
    }
    if(b1>B1)printf("a\n");
    else if(B1>b1)printf("A\n");
    else printf("0\n");
    exit(EXIT_SUCCESS);

}
