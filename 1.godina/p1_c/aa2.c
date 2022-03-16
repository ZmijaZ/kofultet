#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20

int main(){
char s[N]="programiranje";
char c[N]; 
while(scanf("%s",c)!=EOF){
    for(int i=0;i<strlen(s);i++){
     int p=0;
     
        for(int j=0;j<strlen(c);j++)
            if(s[i]!=c[j])p++;
        if(p!=strlen(c))printf("%s",c);
    }
    
}

}
