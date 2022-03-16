#include <stdio.h>
#include <stdlib.h>

void greska(void){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int* alociraj (int n){
    int*a = (int*)malloc(n*sizeof(int));
        if(a == NULL)
            greska();
    return a;
}

void inicijalizuj(int *a, int n){
    int i;
    for(i = 0; i<n; i++)
        scanf("%d", a+i);
    return;
}

void ispisi(int*a, int n){
    int i;
    for(i = 0; i<n; i++)
        printf("%d ", *(a+i));
    printf("\n");
    return;
}

void insertion(int*a, int n){
    int i, j;
    for(i = 1; i<n; i++){
        int pom = a[i];
        for(j=i; j>0 && a[j-1]>pom; j--)
            a[j] = a[j-1];
        a[j] = pom;
    }
    return;
}

void insertionr(int*a, int n){
    int i, j;
    for(i = 1; i<n; i++){
        int pom = a[i];
        for(j=i; j>0 && a[j-1] < pom; j--)
            a[j] = a[j-1];
        a[j] = pom;
    }
    return;
}

void selection(int*a, int n){
    int i, j, min, tmp;
    for(i = 0; i<n; i++){
        min = i;
        for(j = i+1; j<n; j++)
            if(a[j] < a[min])
                min = j;
        tmp = a[i];
        a[i] = a[min];
        a[min] = tmp;
    }
    return;
}

void selectionr(int*a, int n){
    int i, j, max, tmp;
    for(i = 0; i<n; i++){
        max = i;
        for(j = i+1; j<n; j++)
            if(a[j] > a[max])
                max = j;
        tmp = a[i];
        a[i] = a[max];
        a[max] = tmp;
    }
    return;
}

void merge(int*a, int l, int d, int *b){
    if(l>=d)
        return;
    int s = (l+d)/2;
    
    merge(a, l, s, b);
    merge(a, s+1, d, b);
    
    int i = l, j = s+1, k = 0;
    
    while(i<=s && j<=d){
        if(a[i] < a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<=s){
        b[k] = a[i];
        k++;
        i++;
    }
    while(j<=d){
        b[k] = a[j];
        k++;
        j++;
    }
    for(i = l, k = 0; i<=d; i++, k++)
        a[i] = b[k];
}

void merger(int*a, int l, int d, int*b){
    if (l>=d)
        return;
    int s = (l+d)/2;
    
    merger(a, l, s, b);
    merger(a, s+1, d, b);
    
    int i = l, j = s+1, k =0;
    
    while(i<=s && j<=d){
        if(a[i] > a[j]){
            b[k] = a[i];
            i++;
            k++;
        }
        else{
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while(i<=s){
        b[k] = a[i];
        i++;
        k++;
    }
    while(j<=d){
        b[k] = a[j];
        j++;
        k++;
    }
    for(i=l, k=0; i<=d; i++, k++)
        a[i] = b[k];
    
}

int main(){
    int n;
    scanf("%d", &n);
        if(n<1)
            greska();
    int*niz = alociraj(n);
        if(niz == NULL)
            greska();
    inicijalizuj(niz, n);
    int*pom = alociraj(n);
        if(pom == NULL)
            greska();
    
    merge(niz, 0, n-1, pom);
    ispisi(niz,n);
    merger(niz, 0, n-1, pom);
    ispisi(niz, n);
    

free(niz);
exit(EXIT_SUCCESS);
}
