#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define I 11

typedef struct{
    char figura[I];
    int  polje1;
    char polje2;

}SAH;

char konj[]="konj";
char lovac[] = "lovac";
char top[] = "top";
char kraljica[] = "kraljica";

int napada1(SAH f1, SAH f2){
    int p=0;
    if((strcmp(f1.figura,kraljica)==0) && 
    ((f1.polje1==f2.polje1) || ((f1.polje2-49)==(f2.polje2-49)) || (abs(f1.polje1-f2.polje1)==abs((f1.polje2-49)-(f2.polje2-49))))) 
        p=1;
    else if((strcmp(f1.figura,lovac)==0) && (abs(f1.polje1-f2.polje1)==abs((f1.polje2-49)-(f2.polje2-49))))
        p=1;
    else if((strcmp(f1.figura,top)==0) && (f1.polje1==f2.polje1) || ((f1.polje2-49)==(f2.polje2-49)))
        p=1;
    else if((strcmp(f1.figura,konj)==0) && (
    (abs(f1.polje1-f2.polje1)==1 && (abs((f1.polje2-49)-(f2.polje2-49))==2)) ||
    (abs(f1.polje1-f2.polje1)==2 && (abs((f1.polje2-49)-(f2.polje2-49))==1)) ))
        p=1;
    return p;
}


int main(){
SAH a,b; int c,d;
scanf("%s %d %c", a.figura,&a.polje1,&a.polje2);
scanf("%s %d %c", b.figura,&a.polje1,&b.polje2);
c=napada1(a,b);
d=napada1(b,a);
printf("%d %d\n",c,d); 

exit(EXIT_SUCCESS);
}
