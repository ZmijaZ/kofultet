#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define MAX_SIZE 1024
    
int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    if(strcmp(argv[1], "-r") == 0){
        
        int fd = open(argv[2], O_RDONLY | O_EXCL);
            greska(fd != -1, "fd");
        
        int readBytes = 0;
        char buffer[MAX_SIZE];
        
        while( (readBytes = read(fd, buffer, MAX_SIZE))>0){
            
            greska(write(STDOUT_FILENO, buffer, readBytes) != -1, "write");
            
        }
        
        greska(readBytes != -1, "readBytes");

    }
        
    else if(strcmp(argv[1], "-w") == 0){
        
        
        int fd = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0777);
            greska(fd != -1, "fd");
        
        int readBytes = 0;
        char buffer[MAX_SIZE];
        
        while( (readBytes = read(STDIN_FILENO, buffer, MAX_SIZE))>0){
            
            greska(write(fd, buffer, readBytes) != -1, "write");
            
        }
        
        greska(readBytes != -1, "readBytes");
        
    }
        
    else if(strcmp(argv[1], "-a") == 0){
        
        int fd = open(argv[2], O_WRONLY | O_APPEND);
            greska(fd != -1, "fd");
        
        int readBytes = 0;
        char buffer[MAX_SIZE];
        
        while( (readBytes = read(STDIN_FILENO, buffer, MAX_SIZE))>0){
            
            greska(write(fd, buffer, readBytes) != -1, "write");
            
        }
        
        greska(readBytes != -1, "readBytes");     
        
    }
    
        

    
exit(EXIT_SUCCESS);
}

