#include <stdio.h>
#include <stdlib.h>

#define N 10000
#define M 2

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);

}

int prost(int n){
    int p = 1;
    for(int i=2; i<=(n/2); i++)
        if(n%i == 0)
            p = 0;
    return p;
}

int main(int argc, char**argv){
    if(argc!=3 || (atoi(argv[1]) > atoi(argv[2])) || (atoi(argv[2])) > N || (atoi(argv[1])<M) )
        greska();
    for(int i=atoi(argv[1]);i<=atoi(argv[2]);i++){
        if(prost(i))
        printf("%d ", i);
    }
    
printf("\n");
exit(EXIT_SUCCESS);
}
