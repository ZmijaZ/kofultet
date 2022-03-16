#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#include <sys/wait.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
            
#define RD_END 0
#define WR_END 1
    

int main(int argc, char**argv){

    int cld2par[2];
        greska(pipe(cld2par) != -1, "cld2par");
    
    int lineCount = 0;
        
    pid_t childPid = fork();
        greska(childPid != -1, "childPid");
        
    if(childPid > 0){
        
        close(cld2par[WR_END]);
        
        FILE* f = fdopen(cld2par[RD_END], "r");
            greska(f != NULL, "fdopen");
            
        char* line = NULL;
        size_t lineLen = 0;
        
        while(getline(&line, &lineLen, f) != -1){
            
            lineCount++;
            printf("%s", line);
            
        }
        free(line);
        fclose(f);
    }
    else{
        close(cld2par[RD_END]);
        
        greska(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2");
        
        greska(execlp("ls", "ls", "-l", argv[1], NULL) != -1, "exec");
        
        exit(EXIT_SUCCESS);
    }
        
        
    int status = 0;
        greska(wait(&status) != -1, "dd");
    if(WIFEXITED(status) && (WEXITSTATUS(status) == EXIT_SUCCESS) )
        printf("Ukupno linija: %d\n", lineCount);
    else
        printf("Greska\n");
    
exit(EXIT_SUCCESS);
}
