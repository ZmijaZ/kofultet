#include <stdio.h>
#include <stdlib.h>

#define N 2


typedef struct krkr {
    char polje1;
    int  polje2;
    char figura[10];
}SAH;

int napada (SAH f1, SAH f2){
    int niz[N];

    if(f1.figura == "kraljica"){
        if((int)((f1.polje1)-97)==(int)((f2.polje1)-97) || (f1.polje2)==(f2.polje2) || (abs((f1.polje1-97)-(f2.polje1-97))==1 && (abs(f1.polje2 - f2.polje2)==1)))
        niz[0]=1;
        else niz[0]=0;
    }
    if(f2.figura == "kraljica"){
        if( ((f1.polje1-97)==(f2.polje1-97)) || ((f1.polje2)==(f2.polje2)) || (abs((f1.polje1-97)-(f2.polje1-97))==1 && (abs(f1.polje2 - f2.polje2)==1)) )
        niz[1]=1;
        else niz[1]=0;
    }
    if(f1.figura == "top"){
        if( ((f1.polje1-97)==(f2.polje1-97)) || ((f1.polje1)==(f2.polje2)) )
        niz[0]=1;
        else niz [0]= 0;
    }
    if(f2.figura == "top"){
        if( ((f1.polje1-97)==(f2.polje1-97)) || ((f1.polje2)==(f2.polje2)) )
        niz[1]=1;
        else niz [1]= 0;
    }
    if(f1.figura == "lovac"){
        if( abs((f1.polje1-97)-(f2.polje1-97))==1 && abs(f1.polje2 - f2.polje2)==1)
        niz[0]=1;
        else niz[0]=0;
    }
    if(f2.figura == "lovac"){
        if( abs((f1.polje1-97)-(f2.polje1-97))==1 && abs(f1.polje2 - f2.polje2)==1)
        niz[1]=1;
        else niz[1]=0;
    }
    if(f1.figura == "konj"){
        if( (abs((f1.polje1-97)-(f2.polje1-97))==1) && (abs(f1.polje2-f2.polje2)==2) )
        niz[0]=1;
        else if( (abs((f1.polje1-97)-(f2.polje1-97))==2) && (abs(f1.polje2-f2.polje2)==1) )
        niz[0]=1;
        else niz [0]=0;
    }
    if(f2.figura == "konj"){
        if( (abs((f1.polje1-97)-(f2.polje1-97))==1) && (abs(f1.polje2-f2.polje2)==2) )
        niz[1]=1;
        else if( (abs((f1.polje1-97)-(f2.polje1-97))==2) && (abs(f1.polje2-f2.polje2)==1) )
        niz[1]=1;
        else niz [1]=0;
    }
    return niz[N];
    
    }


int main(){
 SAH a;  SAH b;
scanf("%s %c %d",a.figura,&a.polje1,&a.polje2);
scanf("%s %c %d",b.figura,&b.polje1,&b.polje2);
printf("%d",napada(a, b));



}
