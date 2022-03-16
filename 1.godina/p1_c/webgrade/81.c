#include <stdio.h>
#include <stdlib.h>

int prebroj_manje(int x){
int i,b=0;
while(i!=EOF){
scanf("%d",&i);
if(i<x)b++;}
return b;}

int main(){
int x;
scanf("%d",&x);
printf("%d",prebroj_manje(x));
}

