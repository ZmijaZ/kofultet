#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int niven(int n){
    int m = n;
    int sumac = 0;
    while(n){
        sumac+=n%10;
        n/=10;
   }
    if(m % sumac == 0)
        return 1;
    
    return 0;
}

int main(int argc, char**argv){
    if(argc!=2)
        greska();
    int n;
    sscanf(argv[1], "%d", &n);
        if(n<1)
            greska();
    
    int *a = (int*)malloc(n*sizeof(int));
        if(a == NULL)
            greska();
            
    float suma = 0, br = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &a[i]);
        if(a[i] < 1)
            greska();
        if(niven(a[i])){
            suma+=a[i];
            br++;
        }
    }
    if(br == 0)
        printf("%.2f\n", suma);
    else
        printf("%.2f\n", suma/br);

free(a);
a = NULL;
exit(EXIT_SUCCESS);
}
