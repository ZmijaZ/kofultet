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
float arit_sredina(int a[][N], int n){
    float zbir=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            zbir+=a[i][j];
    zbir/=(n*n);
    return zbir;
}



int main(){
int n; int a[N][N]; int b=0;
scanf("%d",&n);
if(n>N||n<1)greska();
ucitaj(a,n);
float as = arit_sredina(a,n);

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if (j==i && a[i][j]<as){
            printf("%d ",a[i][j]); b++;}

for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if(i+j==n-1 && a[i][j]<as){
            printf("%d ",a[i][j]); b++;}

if(b==0)printf("Nema\n");
else printf("\n");
exit(EXIT_SUCCESS);
}
