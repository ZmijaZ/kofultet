#include <stdio.h>

int main() {
int a,b;
scanf("%d %d",&a,&b);
int i;
for(i=a;i<=b;i++){
    printf("%d\n",i);
}
i = a;
while(i<=b){
    printf("%d\n",i);
    i++;
}
do {
    printf("%d\n",i);
    i++;
}while(i-1<b);

}
