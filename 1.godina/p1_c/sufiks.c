#include <stdio.h>
#include <string.h> 

#define N 41

int main(){
char s[N]; char c[N];char p[N]; int i,k=1,res,b=0;
scanf("%s",s); scanf("%s",c);
int max = strlen(s);
int min = strlen(c);
            if (min>max){
                strcpy(p,s);
                strcpy(s,c);
                strcpy(c,p);
            }
for(i=strlen(s)-1;i>0;i--){
    if(s[i]==c[strlen(c)-k])
        b++; else break;
    if (b==strlen(c)) break;
    k++;
}
if(b!=strlen(c))res=-1;
else res=max-min;
            
            
            
printf("%d\n",res);
}


