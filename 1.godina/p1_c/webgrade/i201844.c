#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 21
#define N 100

void greska (void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    char ime[I];
    char zanr[I];
    double ocena;
    
}FILM;

int main(){
FILM film[N]; int n,i; char z[I];int p=0;
scanf("%d",&n);if(n<1||n>N)greska();

for(i=0;i<n;i++){
    scanf("%s %s %lf", film[i].ime, film[i].zanr, &film[i].ocena);
}
scanf("%s", z);

double max=-1;int maxi=0;
for(i=0;i<n;i++){
    if(strcmp(z,film[i].zanr)==0)
        if(film[i].ocena>max){
        max=film[i].ocena;
        maxi=i;p++;}
    }
    
if(p==0)greska();
else
printf("%s\n", film[maxi].ime);

exit(EXIT_SUCCESS);
}
