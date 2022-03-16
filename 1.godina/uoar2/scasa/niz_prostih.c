#include <stdlib.h>
#include <stdio.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int niz(int*a, int n, int*b);

int main(){
    int n;
    scanf("%d", &n);
    int*a = (int*)malloc(n*sizeof(int));
        if(a == NULL)
            greska();
    int*b = (int*)malloc(n*sizeof(int));
        if(b == NULL)
            greska();
        
    for(int i = 0; i<n; i++)
        scanf("%d", a+i);
    int m = niz(a, n, b);
    
    
    for(int i = 0; i<n; i++)
        printf("%d ", *(a+i));
    printf("\n");
     for(int i = 0; i<m; i++)
        printf("%d ", *(b+i));
        
    
    
exit(EXIT_SUCCESS);
}
