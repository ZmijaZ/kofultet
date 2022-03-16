#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 100

typedef struct /*ovde moze bilo sta ne mora struct*/  {
    double visina; 
    double masa;
    char ime[21];
    char prezime[21];
}BMI;

void greska (void){
printf("-1\n");
exit(EXIT_FAILURE);
}

int main(){
int n; int i; int k; double b[N];
BMI niz_ljudi[N];
scanf("%d",&n);
                if (n<1 || n>N)greska();
for(i=0;i<n;i++)
    scanf("%s %s %lf %lf",niz_ljudi[i].ime,niz_ljudi[i].prezime,&niz_ljudi[i].visina,&niz_ljudi[i].masa);

scanf("%d",&k);
if(k>4 || k<1)greska();
for (i=0;i<n;i++)
b[i]=niz_ljudi[i].masa/pow((niz_ljudi[i].visina),2);

for (i=0;i<n;i++){
    if(b[i]<18.5 && k==1)
    printf("%s %s\n",  niz_ljudi[i].ime, niz_ljudi[i].prezime);
    if (b[i]<25 && b[i]>=18.5 && k==2)
    printf("%s %s\n",  niz_ljudi[i].ime, niz_ljudi[i].prezime);
    if (b[i]>=25 && b[i]<30 && k==3)
    printf("%s %s\n",  niz_ljudi[i].ime, niz_ljudi[i].prezime);
    if (b[i]>=30 && k==4)
    printf("%s %s\n",  niz_ljudi[i].ime, niz_ljudi[i].prezime);
}

exit(EXIT_SUCCESS);
}
