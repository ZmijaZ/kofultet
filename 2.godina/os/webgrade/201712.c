#include <sys/stat.h>
#include <sys/types.h>
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

void osMkPublicDir(const char *dname);
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    osMkPublicDir(argv[1]);
    
exit(EXIT_SUCCESS);
}

void osMkPublicDir(const char *dname){
    
    mode_t oldUmask = umask(0);
    
    int fd = mkdir(dname, 0777);
        greska(fd != -1, "mkdir");
    
    umask(oldUmask);
}

