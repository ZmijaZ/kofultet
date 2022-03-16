#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);

}

int broj_delilaca(int n){
    int i, br = 0;
    for(i = 1; i<=n; i++)
        if(n % i == 0)
            br++;
    return br;
}

int main(int argc, char**argv){
    if(argc != 3)
        greska();
    int n, m;
    sscanf(argv[1] ,"%d", &n);
    sscanf(argv[2] ,"%d", &m);
    if(n*m<=0 || n>m)
        greska();
        
    int max = 0, maxi = 0;
    for(int i = n; i<=m; i++){
        if(broj_delilaca(i) > max){
            max = broj_delilaca(i);
            maxi = i;
        }
    }
    
    printf("%d %d\n", maxi, max);
exit(EXIT_SUCCESS);
}
