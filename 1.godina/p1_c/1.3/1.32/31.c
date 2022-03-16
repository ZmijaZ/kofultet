#include <stdio.h>
#include <ctype.h>

int main(){

char c;


while((c=getchar()) != "."){
    if(islower(c)){
    toupper(c);
    }
    if(isupper(c)){
    toupper(c);
    }    
}
printf("%c",c);

}
