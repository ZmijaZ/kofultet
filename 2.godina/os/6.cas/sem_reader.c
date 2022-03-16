#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/mman.h>

#include <semaphore.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define MAX_SIZE 1024
    
typedef struct{
    sem_t semWrite;
    sem_t semRead;
    char buffer[MAX_SIZE];
    
} sharedType_t;
    
void*getMemBlock(char*path, unsigned *size){
    
    int memFd = shm_open(path, O_RDWR | O_CREAT, 0777);
        greska(memFd != -1, "memFd");
        
    struct stat fInfo;
        greska(fstat(memFd, &fInfo) != -1, "stat");
    *size = fInfo.st_size;
    
    void*addr = mmap(NULL, *size, PROT_WRITE | PROT_READ, MAP_SHARED, memFd, 0);
        greska(addr != MAP_FAILED, "mmap");
    close(memFd);
        
    return addr;
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    unsigned size = 0;
    
    sharedType_t* sharedMem = getMemBlock(argv[1], &size);
    
    char buffer[MAX_SIZE];
    
    do {
        
        greska(sem_wait(&(sharedMem->semRead)) != -1, "read");
        strcpy(buffer, sharedMem->buffer);
        greska(sem_post(&(sharedMem->semWrite)) != -1, "read");
        
        printf("Message from write: %s\n", buffer);
        
    }while (strcmp("quit", buffer));
    
    greska(munmap(sharedMem, size) != -1, "munmap");
    
    exit(EXIT_SUCCESS);
}
