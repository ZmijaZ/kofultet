#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

void premesti (int a[], int indeks[], int n){
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    for(i=0;i<n;i++){
    scanf("%d",&indeks[i]);
    if(indeks[i]>=n || indeks[i]<0)greska();
    }
    
    for(i=0;i<n;i++){
    printf("%d ", a[indeks[i]]);
    }
    printf("\n");
}




int main(){
int a[N]; int b[N]; int i,n;

scanf("%d",&n);
if (n>N || n<1)greska();
premesti(a,b,n);
exit(EXIT_SUCCESS);
}
