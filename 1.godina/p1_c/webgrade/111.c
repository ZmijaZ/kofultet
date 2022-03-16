#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define N 101
int main(){
char s[N];
int zbir=0,i;
scanf("%s",s);

for (i=0;s[i]!='\0';i++){
   if (isalpha(s[i])){
       while(s[i]>0){
           zbir+=s[i]%10;
           s[i]/=10;
    }   if(zbir>9){
        zbir= (zbir%10) + zbir/10;
    }
    printf("%d",zbir);
    zbir=0;
}
    else if(isdigit(s[i])){
        s[i]+=49;
        printf("%c",s[i]);
    }
    else{printf("%c",s[i]);}
}
printf("\n");
}
