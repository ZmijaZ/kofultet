#include <stdio.h>
#include <stdlib.h>

int noviBroj(int x, int n){
    if(x==0)
        return 0;
    if( (x%2 == 0) && n)
        return noviBroj(x/10, n-1);
    else
        return (x%10)+10*(noviBroj(x/10,n));

}

int broj_cifara(int x){
    if(x==0)
        return 0;
    return 1+(x/10);
    
}

int main(){
int x,n,p=1;
scanf("%d%d", &x, &n);
    if(n<0){
        fprintf(stderr, "-1\n");
            exit(EXIT_FAILURE);
    }
if (x<0)
    p = -1;
x = abs(x);
if(broj_cifara(x)>n)
    printf("%d\n", p*noviBroj(x,n));
else
    printf("-1\n"); 
exit(EXIT_SUCCESS);
}
