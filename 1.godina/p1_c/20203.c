#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n; int a[N][N]; int rez; int i,j;
scanf("%d",&n);
if(n>N||n<1)greska();

for( i=0;i<n;i++){
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);}
        
int p=1;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        if((i!=j) && a[i][j]!=0)
            p=0;        

if (p==1){
    rez=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i==j)rez*=a[i][j];}
else {
    rez=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            rez+=a[i][j];}
printf("%d\n",rez);
exit(EXIT_SUCCESS);
}
