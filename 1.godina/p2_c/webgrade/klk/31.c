#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char**argv){
    if(argc == 1)
        greska();
int a = atoi(argv[1]), b = atoi(argv[1]); float c = 0;

for(int i=1; i<argc; i++){
    if(atoi(argv[i]) < a)
        a = atoi(argv[i]);
    if(atoi(argv[i]) > b)
        b = atoi(argv[i]);
    c+=atoi(argv[i]);
}
c/=(argc-1);
c = (a+b+c)/3;
for(int i=1; i<argc; i++)
    if(atoi(argv[i]) > c)
        printf("%d ", atoi(argv[i]));

printf("\n");
exit(EXIT_SUCCESS);
}
