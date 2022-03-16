#include <stdio.h>

int main (){

int n;
scanf("%d",&n);
int i,j=0;
int p;
for (i=1;i<=n;i++){
    for (j=0;j<n;j++){
        if((j+i)%n==0)
            printf("%3d",n);
            else
                printf("%3d",(j+i)%n);
    
    
   
    
}
 printf("\n");
}
return 0;
}
