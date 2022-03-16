#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n; int k; int res;
scanf("%d %d", &n,&k);
if(n<1||k<1)greska();

int n1=n; int b=0;
while(n1>0){
    b++;
    n1/=10;
}
if(n/10 == 0)
 res =n;
else if(k>b)
     res=( n%(int)pow(10,(k-b)) ) * ((int)(pow(10,(b-(k-b))))) +n/(int)(pow(10,(k-b)));
else if(b>k) res=(n%(int)pow(10,k))*((int)(pow(10,(b-k) )))+n/(int)(pow(10,k));


printf("%d\n",res);
exit(EXIT_SUCCESS);
}
