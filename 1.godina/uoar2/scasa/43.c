#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

void obrni (int*a, int n);

int main(){
int n; scanf("%d", &n);
if(n<1)
    greska();
    
int *a = (int*)malloc(n*sizeof(int));
    if(a == NULL)
        greska();

for(int i=0; i<n; i++)
    scanf("%d", a+i);

obrni(a, n);
    
for(int i=0; i<n; i++)
    printf("%d ", *(a+i));

exit(EXIT_SUCCESS);
}
