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

int main(int argc, char **argv){
    greska(argc == 2, "argumenti");
    
    int fd = open(argv[1], O_RDONLY);
        greska(fd != -1, "fd");
        
    off_t offset = lseek(fd, 0, SEEK_END);
        greska(offset != (off_t)-1, "lseek");
        
    printf("Velicina fajla: %dB\n.", (int)offset);
        
    close(fd);
exit(EXIT_SUCCESS);
}
