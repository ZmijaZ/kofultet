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
            

#define RD_END 0
#define WR_END 1
#define MAX_SIZE 1024
    
int main(int argc, char**argv){

    int cldToPar[2];
    int parToCld[2];
        
    greska(pipe(cldToPar) != -1, "cldToPar");
    greska(pipe(parToCld) != -1, "parToCld");
    
    pid_t childPid = fork();
        greska(childPid != -1, "fork");
        
    if(childPid > 0){
        
        close(cldToPar[WR_END]);
        close(parToCld[RD_END]);
        
        FILE* f_in = fdopen(cldToPar[RD_END], "r");
            greska(f_in != NULL, "fin");
        
        FILE* f_out = fdopen(parToCld[WR_END], "w");
            greska(f_out != NULL, "fout");
        
        fprintf(f_out, "Neka poruka.\n");
        fflush(f_out); //praznjenje buffera, nezavisno da li je pun
        
        char buffer[MAX_SIZE];
            greska(fgets(buffer, MAX_SIZE-1, f_in) != NULL, "fgest");
            
            printf("%s\n", buffer);
            
        //zatvaranjem stream-a, zatvara se i fd
        fclose(f_in);
        fclose(f_out);
    }
        
    else{
        
        close(cldToPar[RD_END]);
        close(parToCld[WR_END]);
        
        FILE* f_in = fdopen(parToCld[RD_END], "r");
            greska(f_in != NULL, "fin1");
            
        FILE* f_out = fdopen(cldToPar[WR_END], "w");
            greska(f_out != NULL, "fout1");
            
        char buffer[MAX_SIZE];
            greska(fgets(buffer, MAX_SIZE - 1, f_in) != NULL, "fgets1");
            
        time_t now = time(NULL);
        
        int n = strlen(buffer);
        buffer[n-1] = 0;
        strcat(buffer, ctime(&now));
        
        fprintf(f_out, "%s", buffer);
        fflush(f_out);
        
        fclose(f_in);
        fclose(f_out);
        
        exit(EXIT_SUCCESS);
    }

    greska(wait(NULL) != -1, "wait");
    
    
exit(EXIT_SUCCESS);
}
