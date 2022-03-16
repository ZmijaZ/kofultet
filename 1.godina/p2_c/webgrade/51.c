#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr,"-1\n");
    exit(EXIT_FAILURE);
}

int izbaci_parne(int x){
    if(x==0)
        return 0;
    if(x%2==1)
        return 10*(izbaci_parne(x/10))+x%10;
    else
        return izbaci_parne(x/10);
}

int main(int argc, char **argv){
    if(argc!=2)
        greska();
    int x1 = atoi(argv[1]);
    int p = 1;
    if(x1<0)
        p=-1;
    x1=abs(x1);
printf("%d\n", p*izbaci_parne(x1));
    
exit(EXIT_SUCCESS);
}
