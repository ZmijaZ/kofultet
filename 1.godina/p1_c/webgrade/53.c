#include <stdio.h>

int main(){

int n;
scanf("%d",&n);
if (n<0){
    n = -n;
}
if(n>9999 || n<1000){
    printf("-1\n");
    return 1;
}
int h = n/1000;
int s = (n%1000)/100;
int d = (n%100)/10;
int j = n%10;
int brojac= 0;
if (h%2 ==1){
    brojac++;
}
if (s%2 == 0){
    brojac++;
}
if (d%2 == 1){
    brojac++;
}
if (j%2 == 0){
    brojac++;
}
printf("%d\n",brojac);
}
