#include <stdio.h>
#include <stdlib.h>

#define N 50

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n,k,l; int i,j; int a[N][N];

scanf("%d", &n);
if(n<1||n>N)greska();
scanf("%d %d",&k,&l);if(k<0||l>=n||k>N||l>N)greska();


for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
int zbir=0;
for(i=k;i<=l;i++)
    for(j=k;j<=l;j++)
        zbir+=a[k][l];

printf("%d\n",zbir);
exit(EXIT_SUCCESS);
}
