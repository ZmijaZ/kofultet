#include <stdio.h>

int main() {

int n;
scanf("%d",&n);
float a;
scanf("%f",&a);
int brojac = 0;
float p;

int i;
for (i=1;i<n;i++){
    float b;
    scanf("%f",&b);
    if(a*b<=0){
    brojac++;
    }
    p = a;
    a = b;
    b = p;

}
printf("Ukupno promena znaka: %d",brojac);
}
