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
    
    greska(argc == 2, "argumenti");
    
    time_t sekunde = (time_t)atoi(argv[1]);
    
    struct tm* brokenTime = localtime(&sekunde);
        greska(brokenTime != NULL, "localtime");
        
    if(brokenTime->tm_hour >= 0 && brokenTime->tm_hour < 7)
        printf("popodne\n");
    else if(brokenTime->tm_hour >= 7 && brokenTime->tm_hour < 9)
        printf("jutro\n");
    else if (brokenTime->tm_hour >= 9 && brokenTime->tm_hour < 12)
        printf("prepodne\n");
    else if (brokenTime->tm_hour >= 12 && brokenTime->tm_hour < 19)
        printf("popodne\n");
    else if (brokenTime->tm_hour >= 19)
        printf("vece\n");
        
    
exit(EXIT_SUCCESS);
}

