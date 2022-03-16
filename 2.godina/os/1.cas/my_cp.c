#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
    }\
    }while(0)

#define MAX_SIZE 2048
    
int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    int srcFd = open(argv[1], O_RDONLY);
        greska(srcFd != -1, "citanje");
    int destFd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0644);
        greska(destFd != -1, "pisanje");
    
    char buffer[MAX_SIZE];
    int procitan = 0;
    
    while( (procitan = read(srcFd, buffer, MAX_SIZE) > 0) ){
        
        greska(write(destFd, buffer, procitan) != -1, "lose");
        
    }
    
    greska(procitan != -1, "losee");
    
    close(srcFd);
    close(destFd);
exit(EXIT_SUCCESS);
}
