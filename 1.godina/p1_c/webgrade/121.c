#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int b, char*s[]){
    if(b==1){printf("-1\n");exit(EXIT_FAILURE);}
    int max=strlen(s[1]); int i;
    for(i=2;i<b;i++){
        if(strlen(s[i])>max)max=strlen(s[i]);
    }
    printf("%d\n",max);


}
