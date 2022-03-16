#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <poll.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define MAX_SIZE 1024
    
int main(int argc, char**argv){
    
    greska(argc >= 2, "arugmenti");
    
    int nFds = argc -1; //number of nFds
    
    struct pollfd* fds = malloc(nFds*sizeof(struct pollfd));
        greska(fds != NULL , "nfds");
        
    for(int i = 0; i < nFds; i++){
        
        int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
            greska(fd != -1, "fd");
        
        fds[i].fd = fd;
        fds[i].events = POLLIN | POLLERR | POLLHUP;
        fds[i].revents = 0;    
        
    }
    
    int activeFds = nFds;
    char buffer[MAX_SIZE];
    
    while(activeFds){
        
        int retVal = poll(fds, nFds, -1); // -1, cekaj dok se nesto ne desi, potencijalno beskonacno
            greska(retVal != -1, "poll");
            
        for(int i = 0; i<nFds; i++){
            
            if(fds[i].revents & POLLIN){
                
                int readBytes = read(fds[i].fd, buffer, MAX_SIZE-1);
                greska(readBytes != -1, "read");
                
                buffer[readBytes] = 0;
                
                printf("Fifo number: %d\n\t Message: %s\n", i+1, buffer);
                
                fds[i].revents = 0; //mora uvek, inace izbacuje gresku
                
            }
            
            else if(fds[i].revents & (POLLIN | POLLHUP)){
                
                close(fds[i].fd);
                
                fds[i].fd = -1;
                fds[i].events = 0;
                fds[i].revents = 0;
                
                activeFds--;
                
                //sve ovo mora za zatvaranje fd-ova
            }
        }
    }
        
    free(fds);
        
    exit(EXIT_SUCCESS);
}
