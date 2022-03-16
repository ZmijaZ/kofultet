#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int suma_cifara(int n){
    if (n == 0)
        return 0;
    return n%10 + suma_cifara(n/10);
}

int main(int argc, char** argv){
    if(argc!=3)
        greska();
    if( (atoi(argv[1]) > atoi(argv[2])) || (atoi(argv[1])<0) || (atoi(argv[2]) > 10000) )
        greska();
        
    int zbir = 0;    
    for(int i = atoi(argv[1]) ; i<=atoi(argv[2]); i++){
        zbir+=(suma_cifara(i));

    }
    printf("%d\n", zbir);
exit(EXIT_SUCCESS);
}
