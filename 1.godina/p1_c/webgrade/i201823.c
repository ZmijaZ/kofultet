#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 101

void greska (void){
printf("-1\n");
exit(EXIT_FAILURE);
}

int main(){
int n; int i,j; float a[N][N]; float zbir1=0; int b=0;
scanf("%d",&n);
if(n>101 || n<1 || n%2==0)greska();

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%f",&a[i][j]);

for(i=0;i<n;i++){
    float zbir=0;
    for(j=0;j<n;j++){
        if(i!=j)zbir+=fabs(a[i][j]);
    }
    if (fabs(a[i][i])>zbir)b++;
        
}
if (b==n){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            zbir1+=a[i][j];
}
if (b==n)printf("%.2f\n",zbir1);
else printf("0\n");
exit(EXIT_SUCCESS);
}
