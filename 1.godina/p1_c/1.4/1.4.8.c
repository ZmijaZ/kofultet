#include <stdio.h>
#include <math.h>

int prost (int x) {
    int i,p;
    p = 1;
    for (i=2;i<=sqrt(x);i++){
    if (x%i==0)
       p= 0;
     
    
    }
        return p;
    


}

int main(){
int n;
scanf("%d",&n);
if (n<0){
printf("Pogresan unos");
return 1;
}
printf("%d\n",prost(n));



}
