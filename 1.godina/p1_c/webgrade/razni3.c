#include <stdio.h>
#include <stdlib.h>

unsigned povrsina_pravougaonika(int x1, int y1, int x2, int y2){
    int p=0;
    p=abs(x1-x2)*abs(y1-y2);
    return p;
}


int main(){
int x1,x2,y1,y2;
scanf("%d %d %d %d",&x1,&x2,&y1,&y2);
printf("%u\n",povrsina_pravougaonika(x1,x2,y1,y2));
exit(EXIT_SUCCESS);
}
