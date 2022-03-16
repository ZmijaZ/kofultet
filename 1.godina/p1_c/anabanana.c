#include <stdio.h>
#include <string.h>
#define N 101

int main(){
char s[N]; char c[N]; int i,j,rez=0;
scanf("%s",s); scanf("%s",c);

    for (i=0;s[i]!='\0';i++){
        if(s[i]==c[0]){
             int b=1;
            for(j=1;j<strlen(c);j++){
                if(s[i+j]!=c[j])
                    break;
                b++;
            }
            if(b==strlen(c))
                rez++;
        }
    }
    printf("%d\n",rez);
}
