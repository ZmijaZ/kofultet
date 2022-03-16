#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#include <pthread.h>
#include <errno.h>

#include <stdatomic.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
            

#define greska_niti(errNum, poruka)\
    do{\
        int _err = (errNum);\
        if(_err > 0){\
            errno = _err;\
            greska(0, poruka);\
        }\
    }while(0)
    
typedef struct{
    
    int idx;
    char* putanja;
    
}inputData_t;
    
atomic_int globalSum;

void* threadFunc(void*arg){
    
    inputData_t* data = (inputData_t*) arg;
    
    FILE*f = fopen(data->putanja, "r");
        greska(f != NULL, "fopen");
        
    int localSum = 0;
        
    while(fgetc(f) != EOF)
        localSum++;
    
    atomic_fetch_add(&globalSum, localSum);
    
    printf("%s: %d\n", data->putanja, localSum); 
    
    fclose(f);
    
    return NULL;
}

int main(int argc, char**argv){

    greska(argc > 1, "argumenti");
    
    int numThreads = argc-1;
    
    pthread_t* tids = malloc(numThreads*sizeof(pthread_t));
        greska(tids != NULL, "tids");
        
    inputData_t* args = malloc(numThreads*sizeof(inputData_t));
        greska(args != NULL, "args");
        
    atomic_init(&globalSum, 0);
        
    for(int i = 0; i<numThreads; i++){
        
        args[i].idx = i+1;
        args[i].putanja = argv[i+1];
        
        greska_niti(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "niti");
    }    
        
    for(int i = 0; i<numThreads; i++){
        
        greska_niti(pthread_join(tids[i], NULL), "..."); 
        
    }
    
    printf("Ukupno karaktera: %d\n", atomic_load(&globalSum));
    
    free(args);
    free(tids);
    
exit(EXIT_SUCCESS);
}
