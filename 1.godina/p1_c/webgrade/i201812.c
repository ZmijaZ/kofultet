#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 31

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
char s[N]; char c[N];char v[N];char m[N];int k=0; int i,j;
scanf("%s",s);
scanf("%s",c);

if (strlen(s)>strlen(c)){
    strcpy(v,s);
    strcpy(m,c);
}
else if(strlen(c)>strlen(s)){
    strcpy(v,c);
    strcpy(m,s);
}
else greska();
for(i=strlen(v),j=strlen(m);j;i--,j--){
    if (v[i]==m[j])
        continue;
    else if(v[i]!=m[j]){
       k=1; break;}
}
if (k==0)
printf("%ld\n",strlen(v)-strlen(m));
else greska();

exit(EXIT_SUCCESS);
}
