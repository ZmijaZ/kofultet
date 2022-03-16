#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


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
    
#define RD_END (0)
#define WR_END (1)
#define MAX_SIZE 1024
    
int main(int argc, char**argv){
    greska(argc == 1, "argumenti");
    
    int cldToPar[2];
        greska(pipe(cldToPar) != -1,"pipec");
    
    int parToCld[2];
        greska(pipe(parToCld) != -1, "pipep");
        
    pid_t childPid = fork();
        greska(childPid != -1, "fork");
    
    if(childPid > 0){
        
        close(parToCld[RD_END]);
        close(cldToPar[WR_END]);
        
        char buffer[MAX_SIZE];
        sprintf(buffer, "Zdravo");
    
        greska(write(parToCld[WR_END], buffer, strlen(buffer))!=-1, "write");
        
        int readBytes = read(cldToPar[RD_END], buffer, MAX_SIZE-1)
            greska(readBytes != -1, "...");
            
        buffer[readBytes] = 0;//mora ovo ako hocemo da koristimo printf umesto write
        printf("%s", buffer);
        
        close(cldToPar[RD_END]);
        close(cldToPar[WR_END]);
    }
    
    else{
        close(parToCld[WR_END]);
        close(cldToPar[RD_END]);
        
        char poruka[MAX_SIZE];
        int readBytes = read(parToCld[RD_END], poruka, MAX_SIZE -1);
            greska(readBytes != -1, "...");
            
        poruka[readBytes] = 0;
        
        char buffer[MAX_SIZE];
        sprintf(buffer, "Poruka od parenta: %s\n", poruka);
        
        greska(write(cldToPar[WR_END], buffer, strlen(buffer))!=-1, "greska");
        
            close(parToCld[RD_END]);
            close(cldToPar[WR_END]);
            
        exit(EXIT_SUCCESS);
    }
        
    greska(wait(NULL) != -1, "wait");
    
        
    exit(EXIT_SUCCESS);
}
