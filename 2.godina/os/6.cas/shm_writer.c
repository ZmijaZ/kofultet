#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/mman.h>

#include <stdlib.h>
#include <stdio.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

void*createMemBlock(char*path, unsigned size){
    
    int memFd = shm_open(path, O_RDWR | O_CREAT, 0777);
        greska(memFd != -1, "memFd");
        
    greska(ftruncate(memFd, size) != -1, "trunc");
    
    void*addr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, memFd, 0);
        greska(addr != MAP_FAILED, "mmap");
    close(memFd);
        
    return addr;
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    int n = 10;
    int *niz = createMemBlock(argv[1], n*sizeof(int));
    
    for(int i = 0; i<n; i++)
        niz[i] = i*i;
    
    greska(munmap(niz, n*sizeof(int)) != -1, "unpam");
    
    exit(EXIT_SUCCESS);
}

