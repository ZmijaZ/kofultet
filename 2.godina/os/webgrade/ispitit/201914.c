#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    int max = 0;
    char komanda[MAX_SIZE];
    char argument[MAX_SIZE];
    
    char max_komanda[MAX_SIZE];

    
    FILE*f = fopen(argv[1], "r");
        greska(f != NULL, "asd");
            
    while(fscanf(f, "%s", komanda) != EOF){
            
            fscanf(f, "%s", argument);
            
            
        int cldToPar[2];
            greska(pipe(cldToPar) != -1, "cldToPar");
        pid_t childPid = fork();
            greska(childPid != -1, "childPid");
        
            

    
        if(childPid > 0){
        
            close(cldToPar[WR_END]);
        
            char c;
            int brojac = 0;
            FILE*f1 = fdopen(cldToPar[RD_END], "r");
                greska(f1 != NULL, "rdend");
            
            while((c = fgetc(f1)) != EOF){
                brojac++;
            }
        
            if(brojac>max){
                max = brojac;
                strcpy(max_komanda, "");
                strcpy(max_komanda, komanda);
                strcat(max_komanda, " ");
                strcat(max_komanda, argument);
            }
                
            fclose(f1);
            close(cldToPar[RD_END]);
        
        }else{
        
            close(cldToPar[RD_END]);
        
            greska(dup2(cldToPar[WR_END], STDOUT_FILENO) != -1, "dup2");
        
            greska(execlp(komanda, komanda, argument, NULL) != -1, "asd");
        
            exit(EXIT_SUCCESS);
    }
    
    int status = 0;
        greska(wait(&status) != -1, "wait");
        

    }
    
    printf("%s\n", max_komanda);
    
exit(EXIT_SUCCESS);
}

