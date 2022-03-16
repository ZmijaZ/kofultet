#include <stdio.h>
#include <stdlib.h>

int min3 (int a, int b, int c){
    int min;
    if(a<b && a<c)min=a;
    else if(b<c && b<a)min=b;
    else min=c;
    return min;
}


int main(){
int a,b,c;
scanf("%d %d %d" , &a,&b,&c);
printf("%d\n",min3(a,b,c));

}
