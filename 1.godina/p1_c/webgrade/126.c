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
	for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
}
}

int main(){
int i,n,j,m,max; int a[N][N];
scanf("%d",&n); 
if(n<1||n>N)greska();

ucitaj(a,n);
scanf("%d",&m);
if(m+1>n)greska();

max=a[m][0];
for(j=0;j<n;j++){
    if(a[m][j]<max)max=a[m][j];
}

printf("%d\n",max);
}
