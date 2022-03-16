#include <stdio.h>
#include <stdlib.h>

#define N 100
#define I 21

void greska (void){
    printf("-1\n");
    exit(EXIT_FAILURE);

}

typedef struct{
    char naziv[I];
    double masa;
    double cena;
    
}SASTOJAK ;

int main(){
SASTOJAK sastojak[N]; int n,i; double zbir = 0;
scanf("%d",&n);
if (n>100 || n<1)greska();

for(i=0;i<n;i++){
    scanf("%s %lf %lf", sastojak[i].naziv, &sastojak[i].masa, &sastojak[i].cena);
    if (sastojak[i].masa<0 || sastojak[i].cena<0)greska();
}
for(i=0;i<n;i++){
zbir+=(sastojak[i].masa/100)*sastojak[i].cena;
}
printf("%.2lf\n",zbir);
exit(EXIT_SUCCESS);
}
