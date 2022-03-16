#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define I 21
#define N 50

typedef struct {
    char ime[I];
    int x;
    int y;
}TACKA;

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n; TACKA tacka[N]; int max=-1; char tacka1[I]; char tacka2[I]; int i; float zbir[N];
scanf("%d",&n);
if(n<1||n>N)greska();
for(i=0;i<n;i++)
    scanf("%s %d %d\n", tacka[i].ime, &tacka[i].x, &tacka[i].y);

for(i=0;i<n;i++)
    zbir[i]=sqrt( pow((tacka[i].x-tacka[i+1].x),2)+pow((tacka[i].y-tacka[i+1].y),2) );
for(i=0;i<n;i++){
    if (zbir[i]>max){
        max=zbir[i];
        strcpy(tacka1,tacka[i].ime);
        strcpy(tacka2,tacka[i+1].ime);
    }
    
}


printf("%s %s\n",tacka1, tacka2);
exit(EXIT_SUCCESS);
}
