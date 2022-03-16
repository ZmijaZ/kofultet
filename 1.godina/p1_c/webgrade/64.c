#include <stdio.h>
#include <math.h>

int main(){
int n,i,zbir=1;
scanf("%d",&n);
for (i=1;i<=n;i++){
    
    if(i%2==0){
        printf("~0%d~\n",zbir);
        
    }else{printf("~%d~\n",zbir);
        
    }

    zbir+=(int)pow(10,2*i);
    }
    
    
}

