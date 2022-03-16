#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

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
        int _err = (errNum);\
        if(_err > 0){\
            errno = _err;\
            greska(0, poruka);\
        }\
    }while(0)
  
typedef struct{
    
    int id;
}inputData_t;
    
typedef struct{
    
    int result;
}outputData_t;

void* threadFunc(void* arg){
    
    inputData_t* data = (inputData_t*)arg;
    
    printf("Hello from %d thread.\n", data->id);
    
    outputData_t* out = malloc(sizeof(outputData_t));
        greska(out != NULL, "ouyt");
        
    out->result = data->id* data->id;
    
    return out; // mora inace se nit nikad ne zavrsava
}
    
int main(int argc, char**argv){

    greska(argc == 2, "arugmenti");
    
    int numThreads = atoi(argv[1]);
    
    pthread_t* tids = malloc(numThreads * sizeof(pthread_t));
        greska(tids != NULL, "malloc");
        
    inputData_t* args = malloc(numThreads*sizeof(inputData_t));
        greska(args != NULL, "malloc1");
        
    for(int i = 0; i<numThreads; i++){
        
        args[i].id = i + 1;
        greska_niti(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "niti" );
    }
    
    for(int i = 0; i < numThreads; i++){
        
        outputData_t* outData = NULL;
        
        greska_niti(pthread_join(tids[i], (void**)&outData), "ddd");
        
        printf("Thread %d finished. Result: %d\n", i+1, outData->result);
        
        free(outData);
    }
    
    free(args);
    free(tids);
    
exit(EXIT_SUCCESS);
}
