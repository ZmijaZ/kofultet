#include <stdio.h>

int max(int x, int y);

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    
    printf("%d\n", max(x, y));

    return 0;
}
