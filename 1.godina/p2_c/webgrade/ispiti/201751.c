#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int rastuce(int *a, int n){
    int i;
    for(i = 0; i<n-1; i++)
        if(a[i] >= a[i+1])
            return 0;
    return 1;
}

int opadajuce(int *a, int n){
    int i;
    for(i = 0; i<n-1; i++)
        if(a[i] <= a[i+1])
            return 0;
    return 1;
}

int jednaki(int *a, int n){
    int i;
    for(i = 0; i<n-1; i++)
        if(a[i] != a[i+1])
            return 0;
    return 1;
}

int main(int argc, char**argv){
    if (argc == 1)
        greska();
    int i;
    
    int*a = (int*)malloc(argc*sizeof(int));
        if(a == NULL)
            greska();

    for(i = 0; i< argc; i++)
        sscanf(argv[i+1], "%d", &a[i]);
        
    int rezultat = 0;
    
    if(rastuce(a, argc)){
        for(i = 0; i< argc; i++)
            rezultat+=a[i];
        printf("%d\n", rezultat);
            }
    else if(opadajuce(a, argc)){
        for(i = 0; i< argc; i++)
            rezultat*=a[i];
        printf("%d\n", rezultat);
            }
    else if(jednaki(a, argc)){
        rezultat = 0;
        printf("%d\n", rezultat);
        }
    else
        printf("-\n");
         
    
    
free(a);
a = NULL;
exit(EXIT_SUCCESS);
}
