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
    float array[ARRAY_MAX];
    unsigned arrayLen;
    
}OsInputData;
    
void *getMemBlock(char*fpath, unsigned*size){
    
    int memFd = shm_open(fpath, O_RDWR, 0600);
        greska(memFd != -1, "memFd");
        
    struct stat fInfo;
        greska(fstat(memFd, &fInfo) != -1, "fstat");
    *size = fInfo.st_size;
    
    void* arg = mmap(NULL, *size, PROT_READ|PROT_WRITE, MAP_SHARED, memFd, 0);
        greska(arg != MAP_FAILED, "arg");
        
    close(memFd);    
    
    return arg;
}

int cmp(const void *pa, const void* pb) {
    float a = *(float*)pa;
    float b = *(float*)pb;

    if(a < b)
        return 1;
    else if(a > b)
            return -1;
    else return 0;
}

int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    unsigned size = 0;
    OsInputData* niz = getMemBlock(argv[1], &size);
    
    greska(sem_wait(&(niz->inDataReady)) != -1, "wait");
    
    qsort(niz->array, niz->arrayLen, sizeof(float), cmp);
    
    int n = niz->arrayLen/2;
    printf("%f\n", niz->array[n]);
    
exit(EXIT_SUCCESS);
}

