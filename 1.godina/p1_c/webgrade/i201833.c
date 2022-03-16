#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}
int main(){
int i,j,n,p=0,b=0; int a[N][N]; int zbirj, zbiri, zbirk=0;
scanf("%d",&n);
if(n<1 || n>100)greska();

for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
for(i=0;i<n;i++){
    zbirj=0; zbiri=0;
    for(j=0;j<n;j++){
        zbirj+=a[i][j];
        zbiri+=a[j][i];
    }
    if(zbirj==zbiri)b++;
}

if(b==n)p=1;
if(p==1){
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            zbirk+=a[i][j];

printf("%d\n",zbirk);}
else printf("0\n");
exit(EXIT_SUCCESS);
}


