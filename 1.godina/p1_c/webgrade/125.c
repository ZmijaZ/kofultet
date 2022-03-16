#include <stdio.h>
#include <stdlib.h>

#define N 50

void greska (void){
printf("-1\n");
exit(EXIT_FAILURE);
}

void ucitaj(int a[][N], int n){
int i,j;
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    scanf("%d",&a[i][j]);
    }
}
}

int main(){

int a[N][N]; int i,j,n,max;
scanf("%d",&n);
if(n<1||n>N)greska();
ucitaj(a,n);

max=a[0][0];
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if (((i==0)||(i==n-1))||((j==0)||(j==n-1)))
            if(max<a[i][j])max=a[i][j];



printf("%d\n",max);
}
