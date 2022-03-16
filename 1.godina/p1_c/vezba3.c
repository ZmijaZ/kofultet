#include <stdio.h>
#include <stdlib.h>

typedef struct kompleks {
  float re;
  float im;
    
}d;
 
int main(){
    d c;
    scanf("%f %f", &c.re,&c.im);
    printf("%f %f", c.re,c.im);
    
}
