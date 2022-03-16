#include <stdio.h>

int saberi(int a, int b);
void ispisi(void);

int main(){
int a,b;
scanf("%d%d", &a, &b);
ispisi();
printf("%d\n", saberi(a,b));
return 0;
}
