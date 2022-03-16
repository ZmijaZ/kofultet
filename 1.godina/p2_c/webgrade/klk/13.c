#include <stdio.h>
#include <stdlib.h>

int f3(int x){
    if(x==0)
        return 0;
    
    if(x%2 == 1 && ((x/10) % 10) == 2)
        return f3(x/10);
    else
        return 10*f3(x/10) + x%10; 
    

}

int main(){
int n, p=1;
scanf("%d", &n);
if(n<0)
    p=-1;
n = abs(n);
printf("%d\n", p*f3(n));

exit(EXIT_SUCCESS);
}
