#include <stdio.h>
#include <stdlib.h>

#define N 50

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

void ucitaj(int a[][N], int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
}

int main(){
int n; int a[N][N];
scanf("%d",&n);
if(n>N||n<1)greska();
ucitaj(a,n);
int k; int real;
scanf("%d",&k);
if(k<1||k>2*n-1)greska();

real=n-(k);

for(int i=0;i<n;i++)    
    for(int j=0;j<n;j++)
       if(i-real==j)
        printf("%d ",a[i][j]);

printf("\n");
exit(EXIT_SUCCESS);
}
