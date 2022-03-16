#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char**argv){

    if(argc!=5 || (strlen(argv[4]) > 20) )
        greska();
        
int a, b, n;
char*s = (char*)malloc(6*sizeof(char));
    if(s==NULL)
        greska();
a = atoi(argv[1]);
b = atoi(argv[2]);
n = atoi(argv[3]);
printf("%d %d %d", a,b,n);
    if(n<0)
        greska();
        
FILE*ulaz = fopen(argv[4], "r");
    if(ulaz == NULL)
        greska();
FILE*izlaz = fopen("izlaz.txt", "w");
    if(izlaz == NULL)
        greska();
float x; int br = 0;
for(int i=0; i<n; i++){
    fscanf(ulaz, "%f", &x);
    if(x>(float)((a+b)/2))
        br++;
}

printf("%d\n", br);

free(s);
fclose(ulaz);
fclose(izlaz);
exit(EXIT_SUCCESS);
}
