#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <string.h>

#include <sys/epoll.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define MAX_BUFFER 1024
#define MAX_ACTIVE 20
    
typedef struct{
    
    char* name;
    int fd;
    
}  epoll_dt; 

    
int main(int argc, char**argv){
    
    greska(argc >= 2, "arugmenti");
    
    int nFds = argc - 1;
    int epollFd = epoll_create(nFds);
        greska(epollFd != -1, "epoll");
        
    struct epoll_event* fds = malloc(nFds*sizeof(struct epoll_event));
        greska(fds != NULL, "fds");
        
    for(int i = 0; i<nFds; i++){
        
        int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
            greska(fd != -1, "fd");
            
        fds[i].events = EPOLLIN | EPOLLERR | EPOLLHUP;
        
        epoll_dt* data = malloc(sizeof(epoll_dt));
            greska(data != NULL, "data");
            
        data->fd = fd;
        data->name = strdup(argv[i+1]);
            greska(data->name != NULL, "dada");
            
        fds[i].data.ptr = data;
        
        greska(epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, &fds[i]) != -1);
    }
        
    int activeFds = nFds;
    struct epoll_event activeEvents[MAX_ACTIVE];
    char buffer[MAX_SIZE];
        
    while(activeFds){
        
        int numActive = epoll_wait(epollFd, activeEvents, MAX_ACTIVE, -1);
            greska(numActive != -1, "numActive");
            
        for(int i = 0; i< numActive; i++){
            
            if(activeEvents[i].events & EPOLLIN){
                
                epoll_dt* data = (epoll_dt*)activeEvents[i].data.ptr;
                
                int fd = data->fd;
                int readBytes = read(fd, buffer, MAX_SIZE -1);
                    greska(readBytes != -1, "read");
                    
                buffer[readBytes] = 0;
                
                printf("fifo name: %s\n", data->name);
                printf("fifo name: %s\n", buffer);
                
            }
            
        }
        
    }
    
    exit(EXIT_SUCCESS);

}
