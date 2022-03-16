#include <stdio.h>


int main (){
int n;
scanf("%d",&n);
if(n>9999 || n<1000){
    printf("Pogresan unos\n");
    return 1;
}
int h = n /1000;
int s = (n /100) %10;
int d = (n%100)/10;
int j = n%10;
int max = h;
if(s > max){
    max=s;
    }
if(d>max){
    max=d;
    }
if (j>max){
    max =j;
}
printf("Najveca cifra je: %d\n",max);
return 0;
}
