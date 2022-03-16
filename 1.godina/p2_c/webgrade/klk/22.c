#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(){
FILE *ulaz1, *ulaz2, *izlaz;
ulaz1 = fopen("u1.txt", "r");
ulaz2 = fopen("u2.txt", "r");
izlaz = fopen("i.txt", "w");
    if(ulaz1 == NULL || ulaz2 == NULL || izlaz == NULL)
        greska();

int m,n;
fscanf(ulaz1 ,"%d", &n);
fscanf(ulaz2 ,"%d", &m);
    if(n < 0 || m<0)
        greska();
        
char *s = (char*)malloc(51*sizeof(char));
    if(s == NULL)
        greska();
    int i = 0, j = 0;
while(i<n || j<m ){
    if(i<n){
    fscanf(ulaz1, "%s", s);
    printf("%s ", s);
    i++;
    }
    if(j<m){
    fscanf(ulaz2, "%s", s);
    printf("%s ", s);
    j++;
    }
}

free(s);
fclose(ulaz1);
fclose(ulaz2);
fclose(izlaz);
printf("\n");
exit(EXIT_SUCCESS);
}
