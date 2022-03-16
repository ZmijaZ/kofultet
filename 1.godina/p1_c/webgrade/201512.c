#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
int n,i,rez;
scanf("%d %d",&n,&i);
if (i<1 || n<0){
printf("-1\n");
exit(EXIT_FAILURE);
}
rez=(n/(int)pow(10,i)*(int)pow(10,i-1))+(n%(int)pow(10,i-1));
printf("%d\n",rez);
exit(EXIT_SUCCESS);

}
