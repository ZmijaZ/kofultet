#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int main(int argc, char**argv){
    greska(argc == 1, "argumenti");
    
    pid_t childPid = fork();
    
    if(childPid == 0) {
        
        greska(execlp("gcc", "gcc", "-std=c99", "vars.c", "-o", "pipes", NULL) != -1, "...");
        
        exit(EXIT_FAILURE);
    }
    
    int status = 0;
        greska(wait(&status) != -1,"status");
    if(WIFEXITED(status) && (WEXITSTATUS(status) == EXIT_SUCCESS) )
        printf("Uspeh\n");
    else
        printf("Neuspeh\n");
    
    
    exit(EXIT_SUCCESS);
}
