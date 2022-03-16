#include <stdio.h>
#include <stdlib.h>

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
    int n; int *niz;
    scanf("%d", &n);
        if(n<=0)
            greska();
    niz = malloc(n*sizeof(int));
        if(niz==NULL)
            greska();
            
    int i,j;
    for(i=0;i<n;i++)
            scanf("%d", &niz[i]);
    int b=0;
    for(i=0;i<n;i++){
        b=0;
        for(j=0;j<i;j++){
            if(niz[j]<niz[i])
                b++;
                }
        printf("%d ", b); 
        }
printf("\n");    
free(niz);
exit(EXIT_SUCCESS);
}
