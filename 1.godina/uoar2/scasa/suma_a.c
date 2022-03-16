#include <stdio.h>
#include <stdlib.h>

int suma_a(int*a, int n);

int main(){
    int n;
    scanf("%d", &n);
    int*a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
        scanf("%d", a+i);
    
    printf("%d\n", suma_a(a, n));


exit(EXIT_SUCCESS);
}
