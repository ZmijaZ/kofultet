#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 51

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int sufiks(char*c, char*s){
    int p=-1, rec = strlen(s), br = 0;
    for(int i = rec-strlen(c), j = 0; i<rec; i++, j++)
        if(c[j]==s[i])
            br++;
    if(br==strlen(c))
        p = 1;
    return p;
}

int main(){
char *s = (char*)malloc(N*sizeof(char));
char *c = (char*)malloc(N*sizeof(char));
    if(s==NULL || c==NULL)
        greska();
int n;
FILE *ulaz = fopen("dat.txt", "r");
    if(ulaz == NULL)
        greska();
    
fscanf(ulaz, "%s%d", s, &n);
    if(n<0)
        greska();
for(int i=0; i<n; i++){
    fscanf(ulaz, "%s", c);
        if(sufiks(s,c)==1)
            printf("%s ", c);
}
printf("\n");
free(s);
free(c);
fclose(ulaz);
exit(EXIT_SUCCESS);
}
