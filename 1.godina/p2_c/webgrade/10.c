#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

void greska(){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char**argv){
    if(argc!=3)
        greska();
int m = atoi(argv[1]), n = atoi(argv[2]);
int** matrica;
matrica = malloc(m*sizeof(int*));
  if(matrica == NULL)
    greska();
  for(int i=0; i<n; i++){
    matrica[i] = malloc(n*sizeof(int));
    if(matrica[i] == NULL)
      greska();
  }
        if(m<1 || n<1 || m>N || n>N)
            greska();
for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
        scanf("%d", &matrica[i][j]);
int maxi = matrica[0][0], minj = matrica[0][0];
int mj = 0, mi = 0;
for(int i=0; i<m; i++){
    if(matrica[i][0]>maxi){
        maxi=matrica[i][0];
        minj=matrica[i][0];
        mi=i;
    }
    for(int j=0; j<n; j++)
        if(matrica[mi][j]<minj){
            minj=matrica[mi][j];
            mj=j;
        }
}
if(minj==maxi)
    printf("%d %d %d\n", mi, mj, maxi);

exit(EXIT_SUCCESS);
}
