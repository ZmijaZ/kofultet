#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <signal.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

int caughtSIGUSR1 = 0;
int caughtSIGUSR2 = 0;
int stop = 0;
    
void processSignal(int signum){
    
    switch(signum){
        case SIGUSR1:
            caughtSIGUSR1 = 1;
            break;
        case SIGUSR2:
            caughtSIGUSR2 = 1;
            break;
        case SIGTERM:
            stop = 1;
            break;
    }
    
    return ;
}

int main(int argc, char**argv){
    
    (void)argc;
    (void)argv;
    
    int usr1 = 0;
    int usr2 = 0;
    
    do{
        greska(signal(SIGUSR1, processSignal) != SIG_ERR, "sigusr1");
        greska(signal(SIGUSR2, processSignal) != SIG_ERR, "sigusr2");
        greska(signal(SIGTERM, processSignal) != SIG_ERR, "sigterm");
        
        
        if(caughtSIGUSR1){
            usr1++;
            caughtSIGUSR1 = 0;
           
        }
        if(caughtSIGUSR2){
            usr2++;
            caughtSIGUSR2 = 0;
           
        }
        
    }while(!stop);
        
    printf("%d %d\n", usr1, usr2);
    
    
exit(EXIT_SUCCESS);
}

