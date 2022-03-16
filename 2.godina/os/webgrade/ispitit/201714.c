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

int main(int argc, char**argv){
    
    greska(argc == 4, "argumenti");
   
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    
    int fd = open(argv[1], O_RDWR);
        greska(fd != -1, "fd");
        
    off_t offset = lseek(fd, a, SEEK_SET);
        greska(offset != -1, "offset");
        
    struct flock lock;
    
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_CUR;
    lock.l_start = 0;
    lock.l_len = b;
    
    int retVal = fcntl(fd, F_GETLK, &lock);
        greska(retVal != -1, "retVal");
        
   switch(lock.l_type){
        
        case F_UNLCK:
            printf("unlocked\n");
            break;
        case F_RDLCK:
            printf("shared lock\n");
            break;
        case F_WRLCK:
            printf("exclusive lock\n");
            break;
        
    }

    close(fd);
        
    
exit(EXIT_SUCCESS);
}

