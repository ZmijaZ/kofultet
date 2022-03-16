#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 101

int duzina(char s[], int n){
    char c,i=0;
    while((c=getchar())!='\n' && c!=EOF && i<n-1){
        s[i]=c;
        i++;
    }s[i]='\0'; return i;
}

int main(){
    char s[N]; char c[N];
    int l,maxl=0;
    while((l=duzina(s,N))>0){
        if(l>maxl){
            maxl=l;
            strcpy(c,s);
        }
    }
    if(maxl==0)printf("Nije uneto nista\n");
    else printf("Najduza je :%s.\n Duzina je: %d.\n",c,maxl);
    
}
