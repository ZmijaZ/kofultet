#include <stdio.h>


int main() {
int n;
scanf("%d",&n);
while (n%10 ==0){
n = n/10;
if (n==0){
    break;
}
}

printf("Rezultat je: %d\n",n);
}
