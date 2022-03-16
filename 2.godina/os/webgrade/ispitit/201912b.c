#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#include <signal.h>

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

int caughtSIGUSR1 = 0;
int caughtSIGUSR2 = 0;
int caughtSIGINT = 0;
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
        case SIGINT:
            caughtSIGINT = 1;
            break;
    }
    
}

int main(int argc, char**argv){
    
    greska(argc == 1, "argumenti");
    (void)argv;
    
    int brojac = 0;
    
    do{
        
        greska(signal(SIGUSR1, processSignal) != SIG_ERR, "usr1");
        greska(signal(SIGUSR2, processSignal) != SIG_ERR, "usr2");
        greska(signal(SIGINT, processSignal) != SIG_ERR, "sgint");
        greska(signal(SIGTERM, processSignal) != SIG_ERR, "stop");
        
        if(caughtSIGUSR1){
            brojac++;
            caughtSIGUSR1 = 0;
        }
        if(caughtSIGUSR2){
            brojac+=2;
            caughtSIGUSR2 = 0;
        }
        if(caughtSIGINT){
            brojac-=4;
            caughtSIGINT = 0;
        }
        
    }while(!stop);
    
    printf("%d\n", brojac);
    
exit(EXIT_SUCCESS);
}

