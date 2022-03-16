#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 21

int main(){
char s[I]; char prog[] = "programiranje";
int p; int b;

while(scanf("%s",s)!=EOF){
    for(int i=0;i<strlen(s);i++){
        p=0;
        for(int j=0;j<strlen(prog);j++){
            if(s[i]==prog[j])
                p++;
            
        }
        if(p>0)b++;
    }
    if(b==strlen(s))
        printf("%s ",s);
    b=0;
}
exit(EXIT_SUCCESS);
}
