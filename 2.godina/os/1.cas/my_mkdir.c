#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

int main(int argc, char **argv){
    
    greska(argc == 3, "argumenti");
    
    int mode = strtol(argv[2], NULL, 8);
    int retVal = mkdir(argv[1], mode);
    
    greska(retVal !=-1, "mkdir");
    
 exit(EXIT_SUCCESS);
}
