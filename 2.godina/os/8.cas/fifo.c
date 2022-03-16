#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int checkRD(char* name){
    
    int fd = open(name, O_RDONLY | O_NONBLOCK);
        greska(fd != -1, "rdfd");
    
    char c;
    int retVal = read(fd, &c, 1);
    
    if(retVal == 0)
        retVal = 0;
    else if(retVal != -1){
        
        if(errno != EAGAIN)
            greska(0, "ernro");
        
        retVal =  1;
    }
    else{
        
        retVal = 1;
    }
        
    close(fd);
       
    return retVal;
}
    
int checkWR(char* name){
    
    int fd = open(name, O_WRONLY | O_NONBLOCK);
    
    if(fd == -1){
        
        if(errno != ENXIO)
            greska(0, "erno");
            
        return 0;
        
    }
    else{
        
        close(fd);
    }
    
    return 1;
    
}

int main(int argc, char**argv){
    
    (void)argv;
    greska(argc == 3, "arugmenti");
    
    if(argv[1][0] == 'r'){
        if(!checkRD(argv[2]))
            printf("Niko nije otvorio fifo u rd\n");
        else
            printf("Fifo je otvoren u rd modu\n");
    }
    
    else if(argv[1][0] == 'w'){
        
        if(!checkWR(argv[1]))
            printf("Niko nije otvorio fifo u wr\n");
        else
            printf("Fifo je otvoren u wr modu\n");
        
    }
    
    else
        greska(0, "progresan rezim");
    
    exit(EXIT_SUCCESS);
}
