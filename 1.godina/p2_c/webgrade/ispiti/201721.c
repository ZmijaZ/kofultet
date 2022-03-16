#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int zbir_prostih_cinilaca(int n){
    int i;
    int suma = 0;
    for(i = 1; i <= n/2; i++){
        if(n%i == 0)
            suma+=i;
    }
    return suma;
}

int main(int argc, char**argv){

    if(argc!=3)
        greska();
        
    int m, n, i;
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &m);
        if(m<0 || n<0 || m<n)
            greska();

    for(i = n; i<m; i++)
        if(i == zbir_prostih_cinilaca(i))
            printf("%d ", i);
printf("\n");
exit(EXIT_SUCCESS);
}
