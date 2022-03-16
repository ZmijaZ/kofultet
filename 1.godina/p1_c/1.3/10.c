#include <stdio.h>

int main(){
int n,i;
scanf("%d",&n);
int prihod =0,rashod=0, zarada =0;
for(i=1;i<=n;i++){
    int broj;
    scanf("%d",&broj);
    if(broj>0){
    prihod+=broj;
    } else{
    rashod+=broj;
}
 zarada = rashod + prihod;

}
printf("Zarada je: %d\n",zarada);
}
