#include <stdio.h>

int main(){

int n;
scanf("%d",&n);
int i,j;

for (i=0;i<n;){
    for (j = 0; j < n  - 1; j++)
      printf(" ");
    for (j=0;j<n*2-1;j++){
        printf("*");
        
        }
        n-=1;
        printf("\n");
        if(n==0)
            break;
    }
   
 
    





}
