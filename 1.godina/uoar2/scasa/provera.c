#include <stdio.h>
#include <stdlib.h>

int negativni(int*a, int n);

int main(){
    int n;
    scanf("%d", &n);
    int*a = (int*)malloc(n*sizeof(int));
    for(int i = 0; i<n; i++)
        scanf("%d", a+i);
    negativni(a, n);
    for(int i = 0; i<n; i++)
        printf("%d ", *(a+i));
        
printf("\n");
exit(EXIT_SUCCESS);
}
