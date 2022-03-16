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

int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    int pravaPristupa = strtol(argv[2], NULL, 8);
    
    mode_t oldUmask = umask(0);
    
    int fd = open(argv[1], O_CREAT | O_EXCL, pravaPristupa);
        greska(fd != -1, "fd");
    
    umask(oldUmask);
        
    close(fd);

exit(EXIT_SUCCESS);
}
