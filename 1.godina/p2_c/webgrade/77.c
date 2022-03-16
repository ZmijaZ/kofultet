#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int palindrom(char*s){
    int n = strlen(s), i, j, p = 1;
    for(i = 0, j = n-1; i<n; i++, j--)
        if(*(s+i) != *(s+j))
            p=-1;
    return p;
}

int main(int argc, char**argv){
    int br = 0;
    for(int i = 1; i < argc; i++)
        if(palindrom(argv[i]) == 1)
            br++;
printf("%d\n", br);    
    
exit(EXIT_SUCCESS);
}
