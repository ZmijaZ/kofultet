#include <stdio.h>
#include <stdlib.h>

#define I 21
#define N 100

void greska (void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

typedef struct {
    char ime[I];
    char prezime[I];
    double prosek;
    int godina;
}STUDENT;

int main(){
STUDENT student[N]; int n,i, b=0;
scanf("%d",&n);
if (n<1||n>N)greska();

for(i=0;i<n;i++){
    scanf("%s %s %lf %d", student[i].ime,
                          student[i].prezime,
                          &student[i].prosek,
                          &student[i].godina);
    if(student[i].godina<1||student[i].godina>4)greska();
    if(student[i].prosek>9 && student[i].godina ==4)b++;
}

printf("%d\n",b);
exit(EXIT_SUCCESS);
}
