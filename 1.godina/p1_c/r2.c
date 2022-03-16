#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define I 31

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
char s[I]; char c[I]; int a1=0,e1=0,i1=0,o1=0,u1=0; int a2=0,e2=0,i2=0,o2=0,u2=0; int b=0; char max[I]; int i;
scanf("%s %s", s, c);
if(strlen(s)>strlen(c))strcpy(max,s);else strcpy(max,c);


for(i=0;i<strlen(s);i++)
    s[i]=tolower(s[i]);
for(i=0;i<strlen(c);i++);
    c[i]=tolower(c[i]);


for(i=0;i<strlen(max);i++){
    if(s[i]=='a')a1++;
    if(c[i]=='a')a2++;
    if(a1>=1 && a2>=1){b++;break;}
}
for(i=0;i<strlen(max);i++){
    if(s[i]=='e')e1++;
    if(c[i]=='e')e2++;
    if(e1>=1 && e2>=1){b++;break;}
}
for(i=0;i<strlen(max);i++){
    if(s[i]=='i')i1++;
    if(c[i]=='i')i2++;
    if(i1>=1 && i2>=1){b++;break;}
}
for(i=0;i<strlen(max);i++){
    if(s[i]=='o')o1++;
    if(c[i]=='o')o2++;
    if(o1>=1 && o2>=1){b++;break;}
}
for(i=0;i<strlen(max);i++){
    if(s[i]=='u')u1++;
    if(c[i]=='u')u2++;
    if(u1>=1 && u2>=1){b++;break;}
}
printf("%d\n",b);
exit(EXIT_SUCCESS);
}
