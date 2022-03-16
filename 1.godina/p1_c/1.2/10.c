#include <stdio.h>
#include <ctype.h>

int main (){
char a,b,c;
printf("Uneti 3 karaktera: ");
scanf("%c%c%c",&a,&b,&c);
if (!isupper(a) && !islower(a) && !isdigit(a)){
    printf("Pogresan unos");
    return 1;
}
if (!isupper(b) && !islower(b) && !isdigit(b)){
    printf("Pogresan unos");
    return 1;
}
if (!isupper(c) && !islower(c) && !isdigit(c)){
    printf("Pogresan unos");
    return 1;
}
a = tolower(a);
b = tolower(b);
c = tolower(c);
printf("%c%c%c",a,b,c);
}
