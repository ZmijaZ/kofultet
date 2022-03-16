#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <sys/time.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
            

int main(int argc, char**argv){
    
    time_t now;
        greska(time(&now) != -1, "..");
    
    struct tm* brokenTime = localtime(&now);
        greska(brokenTime != NULL, "...");
        
    printf("%d\n", (int)now);

    brokenTime->tm_year++;
    
    time_t newTime = mktime(brokenTime);
        printf("%s", ctime(&newTime));
        
    char timeString[1024];
    strftime(timeString, 1024, "Trenutno vreme: %H:%M:%S", brokenTime);
    
    struct timeval preciseTime;
        greska(gettimeofday(&preciseTime, NULL) != -1, "...");
        
    
    printf("%s\n", timeString);
    
    if(now == preciseTime.tv_sec){
        printf("jednako vreme\n");
    }
    else{
        printf("Razlicito vreme\n");
        
    }
    printf("Mikrosekunde: %d\n", (int)preciseTime.tv_usec);
    
exit(EXIT_SUCCESS);
}
