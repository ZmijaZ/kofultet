#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#include <semaphore.h>
#include <sys/mman.h>

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

#define ARRAY_MAX 1024
    
typedef struct{
    
    sem_t inDataReady;
    int array[ARRAY_MAX];
    unsigned arrayLen;
    
} OsData;
    
void *createMemBlock(char*path, unsigned size){
    
    int memFd = shm_open(path, O_RDWR|O_CREAT, 0600);
        greska(memFd != -1, "memFd");
        
    greska(ftruncate(memFd, size) != -1, "ftruncate");
    
    void *addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, memFd, 0);
        greska(addr != MAP_FAILED, "mmap");
    
    return addr;
}

int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    
    
exit(EXIT_SUCCESS);
}

