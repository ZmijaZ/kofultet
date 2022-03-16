#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int suma(int*a, int n);

int main(){

int n; scanf("%d", &n);
int*a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
        greska();
for(int i=0; i<n; i++)
    scanf("%d", a+i);
printf("%d\n", suma(a, n));

exit(EXIT_SUCCESS);
}
