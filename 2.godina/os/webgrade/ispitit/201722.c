#define _XOPEN_SOURCE 700
#define _POSIX_C_SOURCE 2

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
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    int cldToPar[2];
        greska(pipe(cldToPar) != -1, "cldToPar");
    
    pid_t childPid = fork();
        greska(childPid != -1, "childPid");
        
    if(childPid == 0){
        
        close(cldToPar[RD_END]);
        
        greska(dup2(cldToPar[WR_END], STDOUT_FILENO) != -1, "dup2");
        
        greska(execlp("ls", "ls", "-l", argv[1], NULL) != -1, "execlp");
        
        close(cldToPar[WR_END]);
        
        exit(EXIT_SUCCESS);
    }else{
        
        close(cldToPar[WR_END]);
        
        FILE*f = fdopen(cldToPar[RD_END], "r");
            greska(f != NULL, "fdopen");
            
        char *line = NULL;
        size_t len = 0;
        while(getline(&line, &len, f) != -1) {
            char pp[11];
            sscanf(line, "%s", pp);
            printf("%s\n", pp);
        }

        free(line);
        fclose(f);
        close(cldToPar[WR_END]);
    }
        
        
     int status = 0;
    greska(wait(&status) != -1, "1");

    if(WIFEXITED(status) && WEXITSTATUS(status) != EXIT_SUCCESS) {
        printf("Neuspeh\n");
        exit(EXIT_FAILURE);
    }
   
exit(EXIT_SUCCESS);
}

