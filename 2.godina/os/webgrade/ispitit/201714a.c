#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define greska_niti(errNum, poruka)\
    do{\
        int _err = errNum;\
        if(_err > 0){\
            errno = _err;\
            greska(0, poruka);\
        }\
    }while(0)    

int main(int argc, char**argv){
    
    greska(argc == 4, "argumenti");
    
    struct flock lock;
    
    lock.l_type = F_WRLCK;
    lock.l_whence = F_SEEKSET;
    lock.l_start = atoi(argv[2]);
    lock.l_len = atoi(argv[3]);
    
    int fd = open(argv[1], O_RDWR);
        greska(fd != -1, "fd");
        
    greska(fcntl(fd, F_GETLK, &lock) != -1, "fnctl");
    
exit(EXIT_SUCCESS);
}

