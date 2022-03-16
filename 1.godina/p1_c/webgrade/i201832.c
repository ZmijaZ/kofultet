#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100


int main(){
char s[N]; char c[N]; int i,j,b1,b=0;
scanf("%s %s", s,c);

for(i=0;i<strlen(s);i++){
    b1=0;
    for(j=0;j<strlen(c);j++){
        if(s[i]==c[j]){b++;break;}
        else if(s[i]!=c[j])b1++;
    }
    if(strlen(c)==b1)break;
}
printf("%d\n",b);

}
