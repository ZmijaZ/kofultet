#include <stdio.h>
#include <stdlib.h>

#define N 50

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n,k,l,i,j; int a[N][N]; int suma=0;
scanf("%d %d %d",&n, &k, &l); 
if(n<1||n>N || k>l || k<0 || l<0 || l>=n)greska();
    
for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
for(i=k;i<=l;i++)
    for(j=k;j<=l;j++)
        if((i!=k && i!=l)&&(j==k||j==l))
            suma+=a[i][j];
        else if(i==k||i==l)
            suma+=a[i][j];
    


printf("%d\n",suma);
exit(EXIT_SUCCESS);
}
