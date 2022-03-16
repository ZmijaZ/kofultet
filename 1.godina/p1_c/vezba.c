#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int main(){
int n,i,j=0;
scanf("%d",&n);

for (i=1;i<=n;i++){
        if(i!=1 && i!=n){
            for (j=1;j<=n;j++){
                if(j==1 || j==n || j==i || j==n-i+1){
                    printf("*");}
                    else{printf(" ");}
            }
            printf("\n");
        }else{
            for (j=1;j<=n;j++){
                printf("*");
            }
            printf("\n");
        }
        

  
}

}



