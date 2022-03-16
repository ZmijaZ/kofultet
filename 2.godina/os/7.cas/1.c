#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#include <string.h>
#include <sys/wait.h>
#include <time.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

    
int main(int argc, char**argv){

    greska(argc == 2, "argumenti");
    
    int fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
        greska(fd != -1, "fd");
        
    greska(setvbuf(stdout, NULL, _IONBF, 0) != -1, "...");
    
    printf("Ovo ide na stdout.");
    
    int oldFd = dup(STDOUT_FILENO);
        greska(oldFd != -1, "oldfd");
        
    greska(dup2(fd, STDOUT_FILENO) != -1, "dup2");
    
    printf("Ovo ide u fajl.\n");
    
    greska(dup2(oldFd, STDOUT_FILENO) != -1, "dup21");
    
    printf("Ovo ponovo ide na stdout.\n");
    
    close(fd);
    
exit(EXIT_SUCCESS);
}
