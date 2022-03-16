#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/time.h>
#include <sys/resource.h>

#include <string.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
typedef struct{
    
    struct timeval wallTime;
    struct timeval userTime;
    struct timeval sysTime;
    
}stopWatch_t;
    
void start_stopwatch(stopWatch_t* s){
    
    greska(gettimeofday(&(s->wallTime), NULL) != -1, "gettimeofday");
    
    struct rusage usage;
        greska(getrusage(RUSAGE_SELF, &usage) != -1, "rusage");
        
    memcpy(&(s->userTime), &(usage.ru_utime), sizeof(struct timeval));
    memcpy(&(s->sysTime), &(usage.ru_utime), sizeof(struct timeval));
    
}

void print_time(stopWatch_t* s){
    
    double ss = s->wallTime.tv_sec + s->wallTime.tv_usec/1000000.0;
    printf("Wall time: %.6lfs\n", ss);
    
    ss = s->userTime.tv_sec + s->userTime.tv_usec/1000000.0;
    printf("User time %.6lfs\n", ss);
    
    ss = s->sysTime.tv_sec + s->sysTime.tv_usec/1000000.0;
    printf("Sys time %.6lfs\n", ss);
}

void stop_stopwatch(stopWatch_t* s){
    struct timeval newTime;
        greska(gettimeofday(&newTime, NULL) != -1, "newtime");
    
    struct rusage newUsage;
        greska(getrusage(RUSAGE_SELF, &newUsage) != -1, "usage");
    
    int razlika = (newTime.tv_sec * 1000000 + newTime.tv_usec) - 
    (s->wallTime.tv_sec * 1000000 + s->wallTime.tv_usec);
    
    s->wallTime.tv_sec = razlika/1000000;
    s->wallTime.tv_usec = razlika % 1000000;
    
    
    razlika = (newUsage.ru_utime.tv_sec * 1000000 + newUsage.ru_utime.tv_sec) - 
    (s->userTime.tv_sec * 1000000 + s->userTime.tv_usec);
    
    s->userTime.tv_sec = razlika/1000000;
    s->userTime.tv_usec = razlika % 1000000;
        
    
    razlika = (newUsage.ru_utime.tv_sec * 1000000 + newUsage.ru_utime.tv_sec) - 
    (s->sysTime.tv_sec * 1000000 + s->sysTime.tv_sec * 1000000);
    
    s->sysTime.tv_sec = razlika / 1000000;
    s->sysTime.tv_usec = razlika % 1000000;
}

int main(int argc, char**argv){
    
    (void)argv;
    greska(argc == 1, "arugmenti");
    
    stopWatch_t s;
    
    start_stopwatch(&s);
    
    int i = 0;
    double k = 1;
    
    for(i = 0; i<10000000; i++)
        k*=2;
    
    printf("Proizvod: %lf\n",k);
    
    stop_stopwatch(&s);
    
    print_time(&s);
    
    exit(EXIT_SUCCESS);
}
