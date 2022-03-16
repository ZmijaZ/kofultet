#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);

}

int zameni(int n){
    if(n==0)
        return 0;
    if(n%2 == 0)
        return 10*(zameni(n/10)) + (n%10)/2;
    else
        return 10*(zameni(n/10)) + n%10;

}


int main(int argc, char**argv){
    if(argc!=2)
        greska();
int x; int p=1;
sscanf(argv[1], "%d", &x);
    if(x<0)
        p=-1;
printf("%d\n", p*zameni(abs(x)));

exit(EXIT_SUCCESS);
}
