#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 21
#define MAXN 50

typedef struct{
    char imed[MAXS];
    char imeg[MAXS];
    char stadion[MAXS];
    int gold;
    int golg;

}DUEL;

void greska(void){
    printf("-1\n");
    exit(EXIT_FAILURE);
}

int main(){
int n; int i; DUEL duel[MAXN]; int max=-1; char res[MAXS];
scanf("%d",&n);
                if(n<2||n>MAXN)greska();

for(i=0;i<n;i++){
    gets(duel[i].imed);
    gets(duel[i].imeg);
    gets(duel[i].stadion);
    
    scanf("%d %d", &duel[i].gold, &duel[i].golg);
    if(duel[i].gold<0 || duel[i].golg<0)greska();
}
for(i=0;i<n;i++){
    if(abs(duel[i].gold-duel[i].golg)>max){
        max=abs(duel[i].gold-duel[i].golg);
        strcpy(res,duel[i].stadion);
    }
    
}

printf("%s\n", res);
exit(EXIT_SUCCESS);
}
