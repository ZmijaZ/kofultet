#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 21
#define N 100

typedef struct {
    char boja[I];
    double precnik;
    double cena;
}LOPTA;

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n; LOPTA lopta[N]; double max=-1; int i; int p=0;
scanf("%d", &n);
if(n>N||n<1)greska();

for(i=0;i<n;i++)
    scanf("%s %lf %lf", lopta[i].boja, &lopta[i].precnik, &lopta[i].cena);

char bojal[I]; double cenal;
scanf("%s %lf",bojal, &cenal);

for(i=0;i<n;i++){
    if(strcmp(bojal,lopta[i].boja)==0 && lopta[i].cena<cenal)
        if(max<lopta[i].precnik)
            max=lopta[i].precnik;
}

printf("%.2lf\n",max);
exit(EXIT_SUCCESS);
}
