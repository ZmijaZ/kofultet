#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){printf("-1\n"); exit(EXIT_FAILURE); }


int main(){
int a[N]; float b[N];
int n,i;
scanf("%d",&n);
        if(n<1||n>N)greska();

for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
if(n==1)printf("%.2f",(float)a[0]);
else{
for(i=0;i<n;i++){
if (i==0)b[i]=((float)a[0]+a[n-1]+a[1])/3;
else if (i==n-1)b[i]=((float)a[0]+a[n-1]+a[n-2])/3;
else b[i]=((float)a[i]+a[i-1]+a[i+1])/3;
}

for(i=0;i<n;i++){
    printf("%.2f ",b[i]);
}}
printf("\n");
exit(EXIT_SUCCESS);
}
