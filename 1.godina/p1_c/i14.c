#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Z 5
#define N 51

typedef struct{
    char znak[Z];
    int broj;

}KARTA;

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

void ispisi(KARTA f[], int n, KARTA a){
    for(int i=0;i<n;i++)
        if(strcmp(f[i].znak,a.znak)==0 || f[i].broj==a.broj)
            printf("%s %d\n", f[i].znak, f[i].broj);
    
}

int main(){
int n; KARTA karte[N]; KARTA karta; int b=0;

char h[]="herc";
char p[]="pik";
char t[]="tref";
char k[]="karo";

scanf("%d",&n);
                if (n<1 || n>N)greska();
for(int i=0;i<n;i++){
    scanf("%s %d", karte[i].znak, &karte[i].broj);
    if(karte[i].broj>14||karte[i].broj<1||karte[i].broj==11
      ||(strcmp(karte[i].znak,h)!=0 && strcmp(karte[i].znak,p)!=0 && strcmp(karte[i].znak,t)!=0 && strcmp(karte[i].znak,k)!=0)
    )
        b++;
}
if(b>0)greska();
scanf("%s %d",karta.znak,&karta.broj);
printf("\n");
                
ispisi(karte,n,karta);
exit(EXIT_SUCCESS);
}
