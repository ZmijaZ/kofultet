#include <stdio.h>

void greska (void){
printf("-1\n");
}

int main(){
int x=1,n=0,i; int b[100]; int p =0;
while(x!=0){
    scanf("%d",&x);
    n++;
    if((x>9999||x<1000 && x!=0)){
        b[n]=-1;p=1;
         break;}
    else if(x%2==0 && ((x/1000)%2)==0 && x<9999 && x>1000){
        b[n]=((x%1000)/10)*10+(x%10)*1000+(x/1000);}
    else {b[n]=(x%1000)/10;}

}
if (p ==0){
for (i=1;i<n;i++){
    printf("%d ",b[i]);}
}
else {
for(i=1;i<=n;i++){
    printf("%d ",b[i]);}
}
  printf("\n");
}
