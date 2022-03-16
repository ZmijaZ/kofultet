#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

void ucitaj (int n, int m, int a[][N]){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf("%d", &a[i][j]);
            if(a[i][j]>10 || a[i][j]<0)greska();}
}


int main(){
int i, j, m, n; int a[N][N];int max=-1;int zbir[N];int maxi;int b[N];int zbira;

scanf("%d %d", &n, &m);
if(m>100 || n>100 || n<3 || m<2)greska();
ucitaj(n,m,a);

for(i=0;i<n;i++){
    zbira=0;
    for(j=0;j<m;j++){
        zbira+=a[i][j];
        zbir[i]=zbira;

    }
}

for(i=0;i<n;i++){
    if(zbir[i]>max){
        max=zbir[i];
        maxi=i;
    }
}
for(i=0;i<n;i++){
    if (zbir[i]==max){
        printf("%d\n",i);
    }
    
}

exit(EXIT_SUCCESS);
}
