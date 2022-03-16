#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int n,n1;

scanf("%d",&n);
int max,maxi = 0,rez;
n1 = abs(n);

if (n1<1000 || n1>9999){
    printf("-1\n");
    return 1;
}

int h = n1/1000;
int s = (n1%1000)/100;
int d = (n1%100)/10;
int j = n1%10;

max = j;
if (d > max){
maxi = 1;
max = d;}
if (s >max){
maxi = 2;
max = s;}
if (h>max){
maxi = 3;
max = h;}

rez = n1-(pow(10,maxi));
if (n<0)
rez = -rez;
printf("%d\n",rez);
}
