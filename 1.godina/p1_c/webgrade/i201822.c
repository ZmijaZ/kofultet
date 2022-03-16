#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 31

int main(){
char s[N]; char c; int p=0; char r[N];int k=0,j=0,i;
scanf("%s %c",s, &c); 
for(i=0;i<strlen(s);i++){
    if(c==s[i]) {p=1; j=i; break;}
}
if(p==1){
for(i=j+1; i<strlen(s);i++){
     r[k]= s[i];
     k++;}
for(i=0;i<=j;i++){
    r[k]=s[i];
    k++;
   
}
 r[strlen(s)]='\0';
}
if(p==1)
printf("%s\n",r);
else printf("%s\n",s);
}
