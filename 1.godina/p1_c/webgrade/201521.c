#include <stdio.h>
#include <stdlib.h>

void greska (void){
printf("-1\n");
exit(EXIT_FAILURE);
} 

int main(){
char c1,c2; int g,b;
scanf("%c%c%d%d",&c1,&c2,&g,&b);
    if (c1!='m')greska();


if (g>=0 && g<=20)
    g=2000+g;
else if (g>=20 && g<=99)
    g=1900+g;
else
    greska();


switch(c2){
case 'i':
    printf("informatika %d/%d\n",b,g); 
    exit(EXIT_SUCCESS);
case 'a':
    printf("astronomija %d/%d\n",b,g);
    exit(EXIT_SUCCESS);
case 'r':
    printf("racunarstvo i informatika %d/%d\n",b,g);
    exit(EXIT_SUCCESS);
case 's':
    printf("statistika %d/%d\n",b,g);
    exit(EXIT_SUCCESS);
case 'm':
    printf("teorijska matematika %d/%d\n",b,g);
    exit(EXIT_SUCCESS);
case 'p':
    printf("primenjena matematika %d/%d\n",b,g);
    exit(EXIT_SUCCESS);
default:
    greska();
}

}
