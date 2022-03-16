#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

typedef struct {
	char* indeks;
	int ocena;
	float prosek;
	int br_pon;

}STUDENT;

void greska(void){
fprintf(stderr, "-1\n");
exit(EXIT_FAILURE);
}

int main(){
int n;
scanf("%d", &n);
    if(n<0)
        greska();
STUDENT *niz = (STUDENT*)malloc(N*sizeof(STUDENT));
	if(niz == NULL)
		greska();
for(int i =0; i<n; i++){
	niz[i].indeks = (char*)malloc(n*sizeof(char));
		if(niz[i].indeks == NULL)
			greska();
}

for(int i =0; i<n; i++){
    scanf("%s%d", niz[i].indeks, &niz[i].ocena);
    niz[i].br_pon = 0; niz[i].prosek = 0;
        if(niz[i].ocena >10 || niz[i].ocena < 6)
            greska(); 
}
for(int i =0; i<n; i++){
    for(int j=i;j<n; j++)
        if(strcmp(niz[i].indeks, niz[j].indeks) == 0){
            niz[i].prosek += niz[j].ocena;
            niz[i].br_pon++;
        }
}

for(int i =0; i<n; i++){
    if(niz[i].br_pon){
        niz[i].prosek/=niz[i].br_pon;
        printf("%s %.2f\n", niz[i].indeks, niz[i].prosek);
        
	}
}

exit(EXIT_SUCCESS);
}
