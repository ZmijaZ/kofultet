#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int n;
scanf("%d",&n);
int h = abs(n/1000);
int s = abs(n%1000)/100;
int d = abs((n/10)%10);
int j = abs(n%10);

int max,maxi;
max = j;
maxi = 0;
if (d>max){
    max = d;
    maxi=1;
}
if (s>max){
    max = s;
    maxi = 2;
}
if (h>max){
    max = h;
    maxi = 3;
    }

max = max-1;
int rez = abs(n)-pow(10,maxi);
if (n<0){
rez = -rez;
}
printf("%d\n",rez);

}
