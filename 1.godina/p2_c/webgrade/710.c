#include <stdio.h>
#include <stdlib.h>

int red(int n){
    int p = 1;
    while(n>10){
        if(n%10 <= n/10 % 10)
            p = 0;
        n/=10;
    }
    return p;
}

int main(int argc, char**argv){

int *niz = (int*)malloc((argc-1)*sizeof(int));
    if(niz == NULL){
        fprintf(stderr, "-1\n");
        exit(EXIT_FAILURE);
    }
    
int br = 0;
    
for (int i = 0; i < argc-1; i++){
    sscanf(argv[i+1], "%d", &niz[i]); 
    if(red(abs(niz[i])))
        br++;
}
    

printf("%d\n", br);
free(niz);
exit(EXIT_SUCCESS);
}
