#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
int n;
scanf("%d",&n);
int sv = 1000;
int sm = 1000;
int An = abs(n);


if (An >9999 || An<1000){
    printf("Nepravilan unos\n");
    return 1;
}
int h = An/1000;
int s = (An/100)%10;
int d = (An%100)/10;
int j = An%10;

int max = h;
int min = h;
if(max>s){
    max = s;
    sv = 100;
    }
if(max>d){
    max = d;
    sv = 10;
    }
if(max>j){
    max = j;
    sv = 1;
    }
if(min<s){
    min = s;
    sm = 100;
    }
if(min<d){
    min = d;
    sm = 10;
    }
if(min<j){
    min = j;
    sm = 1;
    }
int rez = An -max*sv + min*sv - min*sm + max*sm;
if (n<0)
    rez = -rez;
printf("Rezultat je: %d\n",rez);
}
