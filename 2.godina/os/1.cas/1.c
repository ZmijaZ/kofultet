#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define greska (izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka)\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int myfopen (char* path, char*mode){
    
    int flags = 0;
    
    switch(mode[0]){
        case 'r':
            flags |= mode[1] == '+' ? O_RDWR : RDONLY;
            break;
        case 'w':
            flags |= mode[1] == '+' ? O_RDWR : O_WRONLY;
            flags |= O_TRUNC;
            flags |= O_CREAT;
        case 'a':
            flags |= mode[1] == '+' ? O_RDWR : O_WRONLY;
            flags |= O_APPEND;
            flags |= O_CREAT;
        default:
            return -1;
        
    }
    
    mode_t pravaPristupa = 0777;
    
    int fd = open(path, flags, pravaPristupa);
    
    return fd;
}

int main(int argc, char** argv){
    
    greska(argc == 3, "argumenti");
    
    int fd = myfopen(argv[1], argv[2]);
    greska(fd!=-1, "my fopen");
    
    close(fd);
    
exit(EXIT_SUCCESS);
}
