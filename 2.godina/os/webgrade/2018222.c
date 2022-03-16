#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h> //mozda ne mora ni to ni ptred

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

typedef struct{
    
    char* path;
    int fd;
    int brBajtova;
    
}data_t;
    
int main(int argc, char**argv){

    greska(argc > 2, "argumenti");
    
    int numOfFifos = argc-1;
    int epollFd = epoll_create(numOfFifos);
        greska(epollFd != -1, "epollFd");
    
    data_t* data = malloc(numOfFifos * sizeof(data_t));
        greska(data != -1, "data");
        
    struct epoll_event* events = malloc(sizeof(struct epoll_event));
        greska(events != -1, "events");
    
    for(int i = 0; i<numOfFifos; i++){
        
        int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
            greska(fd!= -1, "...");
            
        
        
    }
        
exit(EXIT_SUCCESS);
}

