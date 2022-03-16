#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void greska (void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int x,res,b,x1;
while(scanf("%d",&x)!=EOF){
    if(x<0)greska();
    else if(x==0)printf("0 ");
    else if(x<10)printf("%d ", x);
    else {
    x1=x;
    b=0;
    while(x>0){
        b++;
        x/=10;
    }
    res=(x1%10)*(int)(pow(10,b-1))+x1/(int)(pow(10,(b-1)))+(x1%(int)(pow(10,b-1)) /10)*10;
    printf("%d ",res);}
}

}
