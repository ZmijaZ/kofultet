#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXS 31
#define MAXN 50

typedef struct{
    char ime[MAXS];
    int x;
    int y;
}TACKA;

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);

}


int main(){
int n; TACKA tacka[MAXN]; int i,j; int min=-1; int zbir; char ime1[MAXS]; char ime2[MAXS];
scanf("%d",&n);if(n>50||n<2)greska();
for(i=0;i<n;i++)
scanf("%s %d %d", tacka[i].ime, &tacka[i].x, &tacka[i].y);

for(i=0;i<n;i++)
    for(j=0;j<n;j++){
        zbir=sqrt(pow(tacka[i].x-tacka[j].x,2)-pow(tacka[i].y-tacka[j].y,2));
        if(zbir<min){
            min=zbir;
            strcpy(ime1,tacka[i].ime);
            strcpy(ime2,tacka[j].ime);
        }zbir=0;
}
printf("%s %s\n", ime1, ime2);
exit(EXIT_SUCCESS);
}
