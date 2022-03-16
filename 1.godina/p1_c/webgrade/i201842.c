#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 101

int main(){
char s[N]; char t[N]; int p=0,b,i,j;
scanf("%s %s", s, t);
for(i=0;i<strlen(s);i++){
    b=0;
    if (t[0]==s[i]){
    for(j=1;j<strlen(t);j++)
        if(t[j]==s[i+j])
                b++;}
        else continue;
        
        if (b==strlen(t)-1) p++;
    }
printf("%d\n",p);
exit(EXIT_SUCCESS);
}
