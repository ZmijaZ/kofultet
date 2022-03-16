#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#include <sys/wait.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define greska_niti(errNum, poruka)\
    do{\
        int _err = errNum;\
        if(_err > 0){\
            errno = _err;\
            greska(0, poruka);\
        }\
    }while(0)    

#define RD_END 0
#define WR_END 1
#define MAX_SIZE 1024
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    int cldToPar[2];
        greska(pipe(cldToPar) != -1, "cldToPar");
        
    pid_t ChildPid = fork();
        greska(ChildPid != -1, "ChildPid");
        
    if(ChildPid == 0){
        
        close(cldToPar[RD_END]);
        
        greska(dup2(cldToPar[WR_END], STDOUT_FILENO) != -1, "dup2");
        
        greska(execlp("stat", "stat", "--format=%s", argv[1], NULL) != -1, "...");
        
        exit(EXIT_FAILURE);
        
    }
    
    int status = 0;
        greska(wait(&status) != -1, "wait");
        
    close(cldToPar[WR_END]);
    
    char buffer[MAX_SIZE];
    
    int readBytes = read(cldToPar[RD_END], buffer, MAX_SIZE-1);
        greska(readBytes != -1, "readBytes");
        
    buffer[readBytes] = 0;
    
    if(WIFEXITED(status)){
        if(WEXITSTATUS(status) == EXIT_SUCCESS)
            printf("%s", buffer);
        else
            printf("Neuspeh\n");
    }
    else
        printf("Neuspeh\n");
    
exit(EXIT_SUCCESS);
}

