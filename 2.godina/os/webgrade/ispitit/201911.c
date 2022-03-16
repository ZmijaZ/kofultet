#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#include <time.h>

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

int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    time_t sekunde = atoi(argv[1]);
    struct tm* brokenTime = localtime(&sekunde);
        greska(brokenTime != NULL, "localtime");
        
    switch(brokenTime->tm_wday){
        case 0:
            printf("nedelja ");
            break;
        case 1:
            printf("ponedeljak ");
            break;
        case 2:
            printf("utorak ");
            break;
        case 3:
            printf("sreda ");
            break;
        case 4:
            printf("cetvrtak ");
            break;
        case 5:
            printf("petak ");
            break;
        case 6:
            printf("subota ");
            break;
    }
    
    int godine = atoi(argv[2]);
    brokenTime->tm_year+=godine;
    
    time_t noveSekunde = mktime(brokenTime);
    brokenTime = localtime(&noveSekunde);
        greska(brokenTime != NULL, "localTime");
        
    switch(brokenTime->tm_wday){
        case 0:
            printf("nedelja\n");
            break;
        case 1:
            printf("ponedeljak\n");
            break;
        case 2:
            printf("utorak\n");
            break;
        case 3:
            printf("sreda\n");
            break;
        case 4:
            printf("cetvrtak\n");
            break;
        case 5:
            printf("petak\n");
            break;
        case 6:
            printf("subota\n");
            break;
    }
    
    
exit(EXIT_SUCCESS);
}

