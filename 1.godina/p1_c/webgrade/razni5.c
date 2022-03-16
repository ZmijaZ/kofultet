#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned d;
    unsigned m;
    unsigned g;
}Datum;

void sledeci_dan(Datum d){
    switch (d.m){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    if(d.d==31){
    d.m++;
    d.d=1;}
    else d.d++;
    case 4:
    case 6:
    case 9:
    case 11:
    if(d.d==30){
    d.m++; d.d=1;
    }else d.d++;
    case 2:
    if(d.d==29 && d.g%4==0){
        d.d=1; d.m++;}
    else if(d.d==28 && d.g%4!=0){
        d.d=1; d.m++;
    }
    else d.d++;
    case 12:
    if(d.d==31){
    d.d=1; d.m=1;d.g++;
    }
    }
    
    printf("%d.%d.%d\n",d.d,d.m,d.g);
}

int main(){
Datum a;
scanf("%d %d %d",&a.d, &a.m, &a.g);
sledeci_dan(a);

}
