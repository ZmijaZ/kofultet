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
    
    sharedType_t* sharedMem = createMemBlock(argv[1], sizeof(sharedType_t));
    
    greska(sem_init(&(sharedMem->semWrite), 1, 1) != -1, "semWrite");
    greska(sem_init(&(sharedMem->semRead), 1, 0) != -1, "semWrite");
    
    char buffer[MAX_SIZE];
    
    do {
        
        printf("Message for reader: \n");
        scanf("%s", buffer);
        
        greska(sem_wait(&(sharedMem->semWrite)) != -1, "mem");
        strcpy(sharedMem->buffer, buffer);
        greska(sem_post(&(sharedMem->semRead)) != -1, "mem1");
    }while (strcmp("quit", buffer));
    
    greska(munmap(sharedMem, sizeof(sharedType_t)) != -1, "munmap");
    
    exit(EXIT_SUCCESS);
}
