#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 40

int main(){
char s[I]; int b=1;
scanf("%s",s);
for(int i=0;i<strlen(s);i+=3){
    if(s[i]==s[i+3] && s[i+1]==s[i+4] && s[i+2]==s[i+5]){
        b++;
    }else  {printf("%d%c%c%c",b,s[i],s[i+1],s[i+2]); b=1;  ;
}
}
printf("\n");
exit(EXIT_SUCCESS);
}
