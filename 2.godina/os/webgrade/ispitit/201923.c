#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#include <sys/mman.h>
#include <semaphore.h>

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
    
void* getMemBlock(char* path, unsigned*size){
    
    int memFd = shm_open(path, O_RDWR, 0600);
        greska(memFd != -1, "memFd");
    
    struct stat fInfo;
        greska(fstat(memFd, &fInfo) != -1, "stat");
    *size = fInfo.st_size;
    
    void* addr = mmap(NULL, *size, PROT_READ|PROT_WRITE, MAP_SHARED, memFd, 0);
        greska(addr != MAP_FAILED, "mmap");
        
    return addr;
}

int jedinice(int x){
    
    int brojac = 0;
    while( (x&1) == 1)
        brojac++;
    x = x>>1;
    
    return brojac;
}
    
int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    unsigned size = 0;
    OsData* data = getMemBlock(argv[1], &size);
    
    int local_array[ARRAY_MAX];
    int local_array_len;
    
    greska(sem_wait(&(data->inDataReady)) != -1, "wait");
    
    for(int i = 0; i < (int)data->arrayLen; i++){
        if(jedinice(data->array[i]) >= 4){
            local_array[local_array_len] = data->array[i];
            local_array_len++;
        }
    }
    
    greska(munmap(data, size) != -1, "munmap");
    
    data = getMemBlock(argv[2], &size);
    
    for(int i = 0; i<local_array_len; i++){
        data->array[i] = local_array[i];
    }
    data->arrayLen = local_array_len;
    
    greska(sem_post(&(data->inDataReady)) != -1, "post");
    
    greska(munmap(data, size) != -1, "munmap");
    
exit(EXIT_SUCCESS);
}

