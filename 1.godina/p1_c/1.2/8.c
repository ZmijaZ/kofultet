#include <stdio.h>
#include <ctype.h>

int main (){
char n;
printf("Uneti karakter ");
scanf("%c",&n);
printf("ASCII kod je : %d\n",n);
if (n >= 'A' && n<= 'Z'){
    printf("Uneto slovo je: %c\n",n);
    printf("Odgovarajuce malo slovo je: %c\n",n+32);
    printf("ASCII kod je : %d\n",n+32);
}
else if (n >='a' && n<='z'){
    printf("Uneto slovo je: %c\n",n);
    printf("Odgovarajuce veliko slovo je: %c\n",n-32);
    printf("ASCII kod je : %d\n",n-32);
    
}

}
