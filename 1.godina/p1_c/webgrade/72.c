#include <stdio.h>
#include <stdlib.h>

int main ()
{
 char c;
 int b1=0, b2=0, p=1;
 c = getchar();
 while(c != EOF){
  if (c == '[')
    b1++;
  if (c == ']')
    b2++;
  if (b1<b2)
    p=0;
  c = getchar();

 }
 printf("\n%d\n",p);
 return 1;

}
