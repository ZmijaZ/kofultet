#define _XOPEN_SOURCE 700

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
#define MAX_SIZE 257
#define ERROR 4095
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    FILE*f = fopen(argv[1], "r");
        greska(f != NULL, "fopen");
        
    FILE* output = fopen("errors.txt", "w");
        
    char komanda[MAX_SIZE];
    char argument[MAX_SIZE];
    
    while(fscanf(f, "%s", komanda) == 1){
        
        fscanf(f, "%s", argument);
        
        int cldToPar[2];
            greska(pipe(cldToPar) != -1, "cldToPar");
        pid_t childPid = fork();
            greska(childPid != -1, "childPid");
        
        char greske[ERROR];
            
        if(childPid > 0){
            close(cldToPar[WR_END]);
            
            FILE*f1 = fdopen(cldToPar[RD_END], "r");
                greska(f1 != NULL, "fdopen");
                
            int i = 0;
            while((greske[i] = getc(f1)) != EOF){
                i++;
            }
            greske[i] = '\0';
            
            
        }else{
            
            close(cldToPar[RD_END]);
            
            greska(dup2(cldToPar[WR_END], STDOUT_FILENO) != -1, "dup2");
            greska(execlp(komanda, komanda, argument, NULL) != -1, "execlp");
            
            
            close(cldToPar[WR_END]);
            exit(EXIT_SUCCESS);
        }
        
        int status = 0;
        greska(wait(&status) != -1, "Failed to wait procces");

        if(WIFEXITED(status)){
            if(WEXITSTATUS(status) != 0){
                fprintf(output, "%s", greske); 
            }
        }
        else{
            printf("Child didnt exit\n");
        }   
    }
    
     
    

    fclose(output);
    fclose(f);
    
    
exit(EXIT_SUCCESS);
}

