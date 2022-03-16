#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 51

int main(){
char s[I]; char p[] = "pet"; char pet = '5'; int b,b1;
while(scanf("%s",s)!=EOF){
    for(int i=0;i<strlen(s);i++){
        b=0;b1=0;
        if (s[i]==p[0] && s[i+1]==p[1] && s[i+2]==p[2]) 
                b=1;
        else if(s[i]==pet)
                b1=1;
        if( (b==1 || b1==1) && (b!=b1) )printf("%s ",s);
    }
}
printf("\n");
exit(EXIT_SUCCESS);
}
