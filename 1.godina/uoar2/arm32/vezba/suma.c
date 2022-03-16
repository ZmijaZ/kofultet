#include <stdio.h>

int suma(int x, int y);

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    
    printf("%d\n", suma(x, y));

    return 0;
}
