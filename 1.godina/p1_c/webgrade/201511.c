#include <stdio.h>
#include <stdlib.h>

int main(){
char c;
int n1,n2,s;
scanf("%c",&c);
scanf("%d%d",&n1,&n2);

if(n1>999||n1<100||n2>999||n2<100){
printf("-1\n");
exit(EXIT_FAILURE);
}
switch(c){
case 'p':
s=(n1%100)/10+(n2%100)/10;printf("%d\n",s);
break;
case 'n':
s=((n1/100)+(n1%10))+((n2/100)+(n2%10));
printf("%d\n",s);
break;
case 'P':
s=(n1%100)/10+(n2%100)/10;
printf("%d\n",s);
break;
case 'N':
s=((n1/100)+(n1%10))+((n2/100)+(n2%10));
printf("%d\n",s);
break;
default:
printf("-1\n");
}

exit(EXIT_SUCCESS);

}
