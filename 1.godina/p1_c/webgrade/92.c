#include <stdio.h>

int konverzija(char x){
	int tupa;
    tupa =x%10;
    return tupa;
    }
    
int main(){
char c;
while(scanf("%c",&c)!=EOF){
   
    printf("%d",konverzija(c));
  
}

}
