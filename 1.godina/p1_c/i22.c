#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 101

int orf(char rnk[]){
    int p=0;
    for(int i=0;i<strlen(rnk);i++){
        if(rnk[i]=='A' && rnk[i+1]=='U' && rnk[i+2]=='G')
            p++;
        if(rnk[i]!='A' && rnk[i]!='U' && rnk[i]!='G' && rnk[i]!='C')
        p=-1;
    }
    return p;
}

int main(){
char RNK[I];
while(scanf("%s",RNK)!=EOF){
    printf("%d ",orf(RNK));
}
printf("\n");
}
