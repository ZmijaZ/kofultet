#include <stdio.h>
#include <stdlib.h>


int main(){
int n,n1,j=0,i;int a[100];

while(scanf("%d",&n)!=EOF){
    int zbir =0,b=0;
    n1=abs(n);
    while(n1>0){
        b++;
        zbir+=n1%10;
        n1/=10;
    }
    if(zbir%2==0 || b%2==0){
        a[j]=n;
        j++;}
}
for(i=0;i<j;i++){
    printf("%d ",a[i]);
    
}

}
