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

void *getMemBlock(char*path, unsigned*size){
    
    int memFd = shm_open(path, O_RDWR, 0777);
        greska(memFd != -1, "memFd");
    
    struct stat fInfo;
    greska(fstat(memFd, &fInfo) != -1, "fstat");
        
    *size = fInfo.st_size;
    
        
    void*addr = mmap(NULL, *size, PROT_WRITE | PROT_READ, MAP_SHARED, memFd, 0); 
        greska(addr != MAP_FAILED, "mmap");
        
    close(memFd);
    
    return addr;
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    unsigned size = 0;
    int *niz = getMemBlock(argv[1], &size);
    int n = size/sizeof(int);
    
    for(int i = 0; i<n; i++)
        printf("%d ", niz[i]);
    printf("\n");
    
    greska(munmap(niz, size) != -1, "munmap");
    greska(shm_unlink(argv[1]) != -1, "unlink");
    exit(EXIT_SUCCESS);
}

