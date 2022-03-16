#include <stdio.h>
#include <ctype.h>

int main(){
char a,b,c;
printf("Uneti karaktere: ");
scanf("%c %c %c", &a,&b,&c);
int bb = 0;
int p =1;
if (a >= '0' && a<='9'){
p = p*(a-'0');
bb ++;
}
if (b >= '0' && b<='9'){
p = p*(b-'0');
bb++;
}
if(c >= '0' && c<='9'){
p = p*(c-'0');
bb++;
}


if (bb == 0){
printf("Nema cifara\n");
}else { printf("Proizvod je %d\n", p);
    
}

}
