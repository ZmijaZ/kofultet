#include <stdio.h>
#include <math.h>

int main (){
int n;
printf("Uneti ceo 3-ocifren broj ");
scanf("%d",&n);
if (n>999 || n<100){
    printf("Los unos\n");
    return 1;
}
if (pow((n/100),3)+pow(((n/10)%10),3)+pow((n%10),3)==n){
    printf("Jeste Armstrongov broj\n");
}
else{
printf("Nije Armstrongov broj \n");
return 0;
}


}
