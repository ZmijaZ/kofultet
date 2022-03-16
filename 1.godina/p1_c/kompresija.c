#include <stdio.h>
#include <string.h>
#define N 40

int main(){
char s[N]; int i; int kalem =1;


for(i=0;s[i];i++){
    if(s[i]==s[i+3]){
        int b=1;
        for(j=1;j<3;j++){
            if(s[j+i]!=s[j+i+3]){
                break; else b++;
            }
        }if (b==3){kalem++; printf("%d%c%c%c",kalem,s[i]s[i+1]s[i+2]);}
    }

}

}


acgacguaguaguagcccccccgc
