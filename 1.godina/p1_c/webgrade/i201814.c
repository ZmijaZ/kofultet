#include <stdio.h>
#include <stdlib.h>

#define I 21
#define N 100

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct{
    char ime[I];
    char prezime[I];
    double visina;
    double masa;
    double b;
}BMI;

int main(){
BMI osoba[N];int n;int k;int i;
scanf("%d",&n);
            if (n<1 || n>N)greska();
for (i=0;i<n;i++){
    scanf("%s %s %lf %lf",  osoba[i].ime,
                            osoba[i].prezime,
                            &osoba[i].visina,
                            &osoba[i].masa);
    
}

scanf("%d",&k);
            if(k<1||k>4)greska();
for(i=0;i<n;i++)
    osoba[i].b=osoba[i].masa/(osoba[i].visina*osoba[i].visina);

for(i=0;i<n;i++){
if (osoba[i].b < 18.5 && k==1)printf("%s %s\n", osoba[i].ime, osoba[i].prezime);
          
if (osoba[i].b >= 18.5 && osoba[i].b<25 && k==2)printf("%s %s\n", osoba[i].ime, osoba[i].prezime);
          
if (osoba[i].b >=25 && osoba[i].b<30 && k==3)printf("%s %s\n", osoba[i].ime, osoba[i].prezime);
if (osoba[i].b >= 30 && k==4)printf("%s %s\n", osoba[i].ime, osoba[i].prezime);

}
exit(EXIT_SUCCESS);
}
