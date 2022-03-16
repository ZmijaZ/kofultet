#include <stdio.h>
#include <string.h>

int main(){
char s[100]; char c[100];
scanf("%s %s", s, c);
printf("%d\n", strncmp(s,c,3));

return 0;
}
