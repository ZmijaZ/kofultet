#include <stdio.h>
#include <stdlib.h>
#define N 100

void greska (void){
    printf("Greska\n");
    exit(EXIT_FAILURE);}
    
void ucitaj (int niz[], int n){
    int i;
    for (i=0;i<n;i++){
        scanf("%d",&niz[i]);
    }
}
void novi (int niz[],int n){
    int i;
    for (i=0;i<n;i++){
        if (niz[i]%10!=0){
        if (niz[i]%(niz[i]%10)!=0){
            niz[i]=0;}  } }
    for (i=0;i<n;i++){
        if (niz[i]!=0)
            printf("%d ",niz[i]);
    
    }
}

int main(){
int niza[N];
int n; 
scanf("%d",&n);
    if ((n<1) || (n>N)){
    greska();}
ucitaj(niza,n);
novi (niza,n);

exit(EXIT_SUCCESS);
}
