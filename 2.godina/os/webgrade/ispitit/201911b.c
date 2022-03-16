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
    
    time_t sekunde = (time_t)atoi(argv[1]);
    struct tm *brokenTime = localtime(&sekunde);
        greska(brokenTime != NULL, "brokenTime1");
        
    switch(brokenTime->tm_mon){
        case 0: 
            printf("januar ");
            break;
        case 1: 
            printf("februar ");
            break;
        case 2: 
            printf("mart ");
            break;
        case 3: 
            printf("april ");
            break;
        case 4: 
            printf("maj ");
            break;
        case 5: 
            printf("jun ");
            break;
        case 6: 
            printf("jul ");
            break;
        case 7: 
            printf("avugst ");
            break;
        case 8: 
            printf("septembar ");
            break;
        case 9: 
            printf("oktobar ");
            break;
        case 10: 
            printf("novembar ");
            break;
        case 11: 
            printf("decembar ");
            break; 
    }
    
    int dani = atoi(argv[2]);
    brokenTime->tm_mday+=dani;
    time_t nove_sekunde = mktime(brokenTime);
    brokenTime = localtime(&nove_sekunde);
        greska(brokenTime != NULL, "brokenTime");
        
    switch(brokenTime->tm_mon){
        case 0: 
            printf("januar\n");
            break;
        case 1: 
            printf("februar\n");
            break;
        case 2: 
            printf("mart\n");
            break;
        case 3: 
            printf("april\n");
            break;
        case 4: 
            printf("maj\n");
            break;
        case 5: 
            printf("jun\n");
            break;
        case 6: 
            printf("jul\n");
            break;
        case 7: 
            printf("avugst\n");
            break;
        case 8: 
            printf("septembar\n");
            break;
        case 9: 
            printf("oktobar\n");
            break;
        case 10: 
            printf("novembar\n");
            break;
        case 11: 
            printf("decembar\n");
            break; 
    }
    
exit(EXIT_SUCCESS);
}

