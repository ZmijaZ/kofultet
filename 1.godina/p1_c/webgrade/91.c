#include <stdio.h>
#include <stdlib.h>

int prebroj_manje (int x){
    int i,b=0;
    while(scanf("%d",&i)!=EOF){
        if(i<x)b++;
    }return b;}
int main (){
int a;
scanf("%d",&a);
printf("%d\n",prebroj_manje(a));
exit(EXIT_SUCCESS);
}


