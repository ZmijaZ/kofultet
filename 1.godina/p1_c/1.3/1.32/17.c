#include <stdio.h>

int main(){

int n;
scanf("%d",&n);
if (n==0){
    printf("Nisu unete cene\n");
    return 1;
}
int i;
float s =0;
for(i=1;i<=n;i++){
    float broj;
    scanf("%f",&broj);
    s +=broj;
    if (broj <0){
        printf("Uneta je pogresna cena\n");
        break;
        
    }
    
}
printf("%.4f\n",(s/n));

}
