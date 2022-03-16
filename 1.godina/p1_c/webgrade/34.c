#include <stdio.h>

int main(){
int n;
scanf("%d",&n);
int ost = n/10;
int rez = ost+(n%10)*1000;
printf("%d\n",rez);


}
