#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

int main(int argc, char** argv){

    greska(argc == 2, "argumenti");
        
    struct stat fInfo;
    
    int retVal = stat(argv[1], &fInfo);
    
    if(retVal == -1){
        
        if(errno != ENOENT)
            greska(0, "errno");
        
        greska(mkfifo(argv[1], 0777) != -1, "ddd");
    }
    int fd = open(argv[1], O_WRONLY | O_TRUNC);
        greska(fd!=-1, "fd");
    
    srand(time(NULL));
    
    int x;
    char odgovor[30];
        
    do{
        x = rand();
            greska(write(fd, &x, sizeof(int)) != -1, "...");
        printf("Broj je: %d\n", x);
        
        printf("Odgovor je: (yes|no)?\n"); 
        scanf("%s", odgovor);
        
    }while(strcmp(odgovor,"no"));
    
    close(fd);
    
    exit(EXIT_SUCCESS);
}
