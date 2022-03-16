#include <stdio.h>
#include <stdlib.h>

int main() {

int n;
scanf("%d",&n);
int max = 0;
int i;
for (i=1;i<=n;i++){
    int broj;
    scanf("%d",&broj);
    
    if (abs(((broj)%100)/10)>abs((max%100)/10)){
        max =broj;
    }
}

printf("Broj sa najvecom deseticom je: %d\n",max);
}
