#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int armstrong(int x){
    int n = x;
    int br = 0;
    int suma = 0;
    
    while(n){
        br++;
        n/=10;
    }
    n = x;
    while(n){
        suma+=pow(n%10, br);
        n/=10;
    }
    
    return suma;
}


int main(int argc, char**argv){
    if(argc!=3)
        greska();
    int n, m;
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &m);
        if(n<1 || m<1 || n>m)
            greska();

    for(int i = n; i<=m; i++)
        if(i == armstrong(i))
            printf("%d ", armstrong(i));
        
        
printf("\n");
exit(EXIT_SUCCESS);
}
