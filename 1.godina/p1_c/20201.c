#include <stdio.h>
#include <stdlib.h>

#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);

}

int main(){
int n; scanf("%d",&n); float prosek=0; float b=0;
int a[N]; float zbir =0; float res;
if (n>N || n<2)greska();

for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    prosek+=a[i];
    b++;}
prosek=prosek/b;

for(int i=0;i<n;i++)
    zbir+=(a[i]-prosek)*(a[i]-prosek);

res=(1/(b-1))*zbir;

printf("%.3f\n",res);
exit(EXIT_SUCCESS);
}
