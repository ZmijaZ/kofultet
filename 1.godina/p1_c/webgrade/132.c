#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}


#define N 100
#define I 31

typedef struct {
    char ime[I];
    double poeni;

}TAKMICAR;

void ispisi3(TAKMICAR a[], int n){
    int i;
    for(i=0;i<3;i++)
        printf("%s ", a[i].ime);

}

int main(){
TAKMICAR takmicar[N]; int n; int tmp; int i; char stmp[I];
scanf("%d",&n);
if(n<3||n>N)greska();

for(i=0;i<n;i++){
    scanf("%s %lf", takmicar[i].ime, &takmicar[i].poeni);
    if(takmicar[i].poeni>100 || takmicar[i].poeni<0)greska();
}

for(i=0;i<=n;i++)
    if(takmicar[i+1].poeni>takmicar[i].poeni){
        tmp=takmicar[i].poeni;
        takmicar[i].poeni=takmicar[i+1].poeni;
        takmicar[i+1].poeni=tmp;
        
        strcpy(stmp,takmicar[i].ime);
        strcpy(takmicar[i].ime,takmicar[i+1].ime);
        strcpy(takmicar[i+1].ime,stmp);
    }

ispisi3(takmicar,n);
printf("\n");

exit(EXIT_SUCCESS);
}
