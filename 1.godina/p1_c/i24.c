#include <stdio.h>
#include <stdlib.h>

#define N 100
#define I 3

typedef struct {
    char naziv[I];
    int tip;
    double gram;
}ELEMENT;


void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n; ELEMENT element[N]; double zbir0=0, zbir1=0, zbir=0; int b1=0, b0=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
    scanf("%s %d %lf", element[i].naziv, &element[i].tip, &element[i].gram); 
    if(element[i].tip!=0 && element[i].tip!=1)greska();
    zbir+=element[i].gram;
}
if(zbir<99||zbir>101) greska();
else {
for(int i=0;i<n;i++){
    if(element[i].tip==0)
        zbir0+=element[i].gram;
    else if(element[i].tip==1)
        zbir1+=element[i].gram;
    else greska();
}
printf("%.2lf %.2lf\n",zbir0/zbir*100,zbir1/zbir*100);

}


exit(EXIT_SUCCESS);
}
