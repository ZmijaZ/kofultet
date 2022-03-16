#define _GNU_SOURCE //jednom definisan signal hendler, vazice stalno, onda ne mora da se pisu cekerori u petlji

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <signal.h>

#include <stdio.h>
#include <stdlib.h>

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
    
}
    
int main(int argc, char** argv){
    (void)argv;
    greska(argc == 1, "argumenti");
    
    
    do{
        greska(signal(SIGUSR1, processSignal) != SIG_ERR, "sigerr1");
        greska(signal(SIGUSR2, processSignal) != SIG_ERR, "sigerr2");
        greska(signal(SIGTERM, processSignal) != SIG_ERR, "sigerrt");
        
        pause();
        
        if(caughtSIGUSR1){
            
            printf("SIGUSR\n");//sme ovde ali ne sme unutar fje jer je signalhendler
            caughtSIGUSR1 = 0;
        }
        
        if(caughtSIGUSR2){
            printf("SIGUSR2\n");
            caughtSIGUSR2 = 0;
        }
        
        if(stop){
            
            printf("SIGTERM\n");
        }
        
    }while(!stop);
    
    exit(EXIT_SUCCESS);
}
