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

typedef struct{
    
    sem_t inDataReady;
    float array[ARRAY_MAX];
    unsigned arrayLen;
    
}OsInputData;

void *getMemBlock(char* fpath, unsigned* size){
    
    int memFd = shm_open(fpath, O_RDWR, 0600);
        greska(memFd != -1, "memFd");
        
    struct stat fInfo;
        greksa(fstat(memFd, &fInfo) != -1, "fstat");
        
    *size = fInfo.st_size;
    
    void* addr = mmap(NULL, *size, PROT_READ|PROT_WRITE, MAP_SHARED, memFd, 0);
        greska(addr != MAP_FAILED, "mmap");
    
    return addr;
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    int size = 0;
    OsInputData *mem = getMemBlock(argv[1], &size);
    
    greska(sem_wait(&(mem->inDataReady)) != -1, "sem_wait");
    
    
exit(EXIT_SUCCESS);
}

