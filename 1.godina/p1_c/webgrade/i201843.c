#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

void trans(float a[][N], int n,float b[][N]){
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            b[j][i]=a[i][j];
}

float najmanji(float a[][N],int n){
    float min=a[0][0]; int j,i;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]<min)
                    min=a[i][j];
    return min;
    
}

float najveci(float a[][N],int n){
    float max=a[0][0]; int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(a[i][j]>max)
                    max=a[i][j];
    return max;
    
}
int dijag (float a[][N], float b[][N], int n){
    int i,j,p=0,r=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(j==i)
                if(a[i][j]==b[i][j])
                    r++;
    if (b==n)p++;
    return p;
}

int main(){
int n,i,j,p=0; float a[N][N]; float b[N][N];
scanf("%d", &n);
if(n<1 || n>N)greska();

for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        scanf("%f",&a[i][j]);
}
trans(a,n,b);

for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        if(-1*a[i][j]==b[i][j]);
            p++;
}
if(p==n*n-n)
    printf("%.2f\n",najmanji(a,n));
else printf("%.2f\n",najveci(a,n));
exit(EXIT_SUCCESS);    
}
