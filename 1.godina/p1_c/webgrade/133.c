#include <stdio.h>
#include <stdlib.h>

#define N 100
#define I 21

void greska (void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}
typedef struct {
    char ime[I];
    double cena;
    char tip;
}PROIZVOD;


int main(){
int n; int i; PROIZVOD proizvod[N]; char c; int m,l; char k;int b=0;
scanf("%d",&n);
                if(n<3||n>N)greska();
for (i=0;i<n;i++){
scanf("%s %lf %c\n", proizvod[i].ime, &proizvod[i].cena, &proizvod[i].tip);
    if(!(proizvod[i].tip=='i' || proizvod[i].tip =='h') || proizvod[i].cena<0)
        greska();}
        
scanf(" %c",&c);
if(c=='r'){
scanf("%d %d", &m,&l);
for(i=0;i<n;i++){
if(proizvod[i].cena>=m && proizvod[i].cena<=l)
printf("%s\n",proizvod[i].ime);}
}

else if(c=='t'){
scanf(" %c", &k);
if(k=='i'){
for(i=0;i<n;i++)
    if(proizvod[i].tip=='i'){
        b++;
        printf("%s\n",proizvod[i].ime);}
}
if(k=='h'){
    for(i=0;i<n;i++)
        if(proizvod[i].tip == 'h'){
                b++;
            printf("%s\n",proizvod[i].ime);}
}

if(b==0)printf("0\n");
}else greska();

exit(EXIT_SUCCESS);
}




