#include <stdio.h>
#include <math.h>

int main(){
int a,b,c,rez=0;
scanf("%d/%d-%d",&a,&b,&c);

if(a%2==0){
while (c>0){
rez+=(int)pow(c%10,3); c/=10;
}
while(b>0){
rez+=(int)pow(b%10,3); b/=10;
}
}else{
while(b>0){
rez+=b%10; b/=10;
}
while(c>0){
rez-=c%10;c/=10;
}
}
printf("%d\n",rez);
}
