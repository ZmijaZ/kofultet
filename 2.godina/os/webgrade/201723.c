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

int main(int argc, char**argv){
    
    greska(argc == 4, "argumenti");
    
    int pravaPristupa = strtol(argv[3], NULL, 8);
    
    if(strcmp(argv[1], "-f") == 0){
        int fd = open(argv[2], O_CREAT, pravaPristupa);
            greska(fd != -1, "fd");
        greska(chmod(argv[2], pravaPristupa) != -1, "chmod");
    }
    else if(strcmp(argv[1], "-d") == 0){
        int retVal = mkdir(argv[2], pravaPristupa);
            greska(retVal != -1, "retVal");
        greska(chmod(argv[2], pravaPristupa) != -1, "chmod");
    }
    else
        greska(0, "pogresan unos");
    
exit(EXIT_SUCCESS);
}

