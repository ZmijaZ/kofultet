#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

int main(int argc, char** argv){

    greska(argc == 2, "argumenti");
    
    int fd = open(argv[1], O_RDONLY);
        greska(fd != -1, "fd");
    
    int x;
    int readBytes;
    
    while((readBytes = read(fd, &x, sizeof(int))) > 0){
        
        printf("Number received: %d\n", x);
    }
        
    greska(readBytes != -1, "...");
    
    close(fd);
        
    exit(EXIT_SUCCESS);
}
