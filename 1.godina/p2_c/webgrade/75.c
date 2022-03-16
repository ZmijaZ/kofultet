#include <stdio.h>
#include <stdlib.h>

#define N 51

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char**argv){
    if(argc!= 3)
        greska();
char*rec = (char*)malloc(N*sizeof(char));
    if(rec == NULL)
        greska();
FILE*ulaz = fopen(argv[1], "r");
    if(ulaz == NULL)
        greska();
int n;
    sscanf(argv[2], "%d", &n);
    if(n<1)
        greska();
int br = 0;
while(fscanf(ulaz, "%s", rec) != EOF){
    br++;
    if(br%n == 0)
    printf("%s ", rec);
}

printf("\n");

free(rec);
fclose(ulaz);
exit(EXIT_SUCCESS);
}
