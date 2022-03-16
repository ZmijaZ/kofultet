#include <stdio.h>
#include <stdlib.h>

int main(){
int x,x1;

while(scanf("%d",&x)!=EOF){
x1=abs(x);
int zbir1=0;int y1;
y1=x1%10;
x1=x1/10;
while(x1>0){
    zbir1+=x1%10;
    x1/=10;
}
if(y1>zbir1)printf("%d ",x);

}

}
