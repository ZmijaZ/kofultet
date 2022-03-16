#include <stdio.h>
#include <string.h>

#define N 101

int main(){
char s[N];char c[N]; int i,b=0;
scanf("%s",s); scanf("%s",c);

for(i=0;s[i];i++){
    if(s[i]=='a' && c[i]!='t')b++;
    if(s[i]=='t' && c[i]!='a')b++;
    if(s[i]=='c' && c[i]!='g')b++;
    if(s[i]=='g' && c[i]!='c')b++;
}
printf("%d\n",b);
    
}
