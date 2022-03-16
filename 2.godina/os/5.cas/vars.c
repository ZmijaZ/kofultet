#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


#include <stdio.h>
#include <stdlib.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int main(int argc, char**argv){
    greska(argc == 1, "argumenti");
    
    int x = 10;
    int y = 5;
    
    pid_t childPid = fork();
        greska(childPid != -1, "childPid");
        
    if(childPid > 0){
        
        x+=20;
        y-=20;
        
        printf("Parent: %d %d\n", x, y);
    }
    else{
        x-=20;
        y+=20;
        
        printf("Child: %d %d\n", x, y);
        
        exit(EXIT_SUCCESS);
    }
    
    printf("Parent agin: %d %d\n", x, y);
    
    int status = 0;
        greska(wait(&status) != -1, "status");
        
    if(WIFEXITED(status) && (WEXITSTATUS(status) == EXIT_SUCCESS))
        printf("Uspeh\n");
    else
        printf("Neuspeh\n");
        
    exit(EXIT_SUCCESS);
}
