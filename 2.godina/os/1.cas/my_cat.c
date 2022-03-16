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
    
#define MAX_SIZE 2048
    
int main(int argc, char**argv){
   
    greska(argc == 2, "argumenti");
    
    int fd = open(argv[1], O_RDONLY);
        greska(fd!=-1, "mycat");
    
    int procitan = 0;
    char buffer[MAX_SIZE];
    
    while ((procitan = read(fd, buffer, MAX_SIZE)) > 0){
        greska(write(STDOUT_FILENO, buffer, procitan) !=-1, "ispisan");
        
    }
    
    greska(procitan != -1, "ucitan");
    
    close(fd);
exit(EXIT_SUCCESS);
}
