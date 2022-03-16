#include <stdio.h>

int main(){
int a,b,c;  int rez=0;
scanf("%d/%d-%d",&a,&b,&c);

if(a==64||a==65||a==66){
while(b>0){
rez+=(b%10)*(b%10);
b/=10;}
while(c>0){
rez+=(c%10)*(c%10);
c/=10;}
printf("%d\n",rez);
return 0;
}
else if(a==60 || a==61 || a==68){
while(b>0){
rez+=b%10;
b/=10;}
printf("%d\n",rez);
return 0;
}
else if(a==62 || a==63 || a==69){
while(c>0){
rez+=c%10;
c/=10;}
printf("%d\n",rez);
return 0;
}
else {
printf("-1\n");
return 0;
}
}
