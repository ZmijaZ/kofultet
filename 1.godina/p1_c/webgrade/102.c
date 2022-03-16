#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

void greska(void){
printf("-1\n");
exit(EXIT_FAILURE);
}

int main(){
int a[N];
int n,i;          int zbir=0,bp=0,bn=0,zbir1=0;
scanf("%d",&n);
        if (n<2 || n>100)greska();
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
for (i=0;i<n;i++){
if (i%2==0){
zbir+=a[i];
bp++;}
if (i%2==1){
zbir1+=a[i]*a[i];
bn++;}
}
float rez = ((float)zbir/(float)(bp)) + (sqrt((float)zbir1/(float)bn));
printf("%.2f\n",rez);
exit(EXIT_SUCCESS);

}
