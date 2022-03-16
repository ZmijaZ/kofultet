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

int main(int argc, char**argv){
    
    greska(argc == 1, "argumenti");
    (void)argv;
    
    do{
        
      
        
        greska(signal(SIGUSR1, processSignal) != SIG_ERR, "1");
        greska(signal(SIGUSR2, processSignal) != SIG_ERR, "2");
        greska(signal(SIGTERM, processSignal) != SIG_ERR, "s");
        
        if(caughtSIGUSR1){
              int n;
            scanf("%d", &n);
            printf("%d\n", abs(n));
            caughtSIGUSR1 = 0;
        }
        if(caughtSIGUSR2){
              int n;
            scanf("%d", &n);
            printf("%d\n", n*n);
            caughtSIGUSR2 = 0;
        }
        
        
    }while(!stop);
    
exit(EXIT_SUCCESS);
}

