#include <stdio.h>
#include <stdlib.h>
int main(){
int i,i1;

while(scanf("%d",&i)!=EOF){
    i1=abs(i);
    int zbir =0,b=0;
    while(i1>0){
        zbir+=i1%10;
        b++;
        i1/=10;
    }
    if(zbir%2==0 || b%2==0){
        printf("%d ",i);
    }
}

}
