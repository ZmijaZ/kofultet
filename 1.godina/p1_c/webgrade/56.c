#include <stdio.h>
#include <stdlib.h>
int main(){

int k,l,m,n;

scanf("%d",&k);
if (k>8||k<1){
printf("-1\n");
    return 1;}
scanf("%d",&l);
if (l>8||l<1){
printf("-1\n");
    return 1;}
scanf("%d",&m);
if (m>8||m<1){
printf("-1\n");
    return 1;}
scanf("%d",&n);
if (n>8||n<1){
printf("-1\n");
    return 1;}
if(k==m && l==n){
    printf("-1\n");
    return 1;
}


if  ((k+l)%2 == (m+n)%2){
    printf("Polja su iste boje.\n");
    }else{ printf("Polja su razlicite boje.\n"); }
    
if((k==m)||(l==n)||abs(k-m)==abs(l-n))
    printf("Kraljica sa (%d,%d) ugrozava polje (%d,%d).\n",k,l,m,n);
    else printf("Kraljica sa (%d,%d) ne ugrozava polje (%d,%d).\n",k,l,m,n);
    
if(abs((k-m))==2){
    if(abs((l-n))==1){
        printf("Konj sa (%d,%d) ugrozava polje (%d,%d).\n",k,l,m,n);
    }else{printf("Konj sa (%d,%d) ne ugrozava polje (%d,%d).\n",k,l,m,n);}
    
} else if (abs((l-n))==2){
        if(abs((k-m))== 1){
            printf("Konj sa (%d,%d) ugrozava polje (%d,%d).\n",k,l,m,n);}
        else printf("Konj sa (%d,%d) ne ugrozava polje (%d,%d).\n",k,l,m,n);
}else printf("Konj sa (%d,%d) ne ugrozava polje (%d,%d).\n",k,l,m,n);

    
    
return 0;
}
