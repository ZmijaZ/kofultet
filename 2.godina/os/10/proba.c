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
    
typedef struct {
    
  int id;  
}dataInput_t;
    
typedef struct{
    
    int result;
}dataOutput_t;

void* pthreadFunc(void*arg){
    
    dataInput_t* data = (dataInput_t*)arg;
    printf("Hello from %d thread.\n", data->id);
    
    dataOutput_t* out = malloc(sizeof(dataOutput_t));
        greska(out != NULL, "out");
        
    out->result = data->id*data->id;
    
    return out;
}

int main(int argc, char**argv){

    greska(argc == 2, "argumenti");
    
    int n = atoi(argv[1]);
    
    pthread_t* tIDs = malloc(n*sizeof(pthread_t));
        greska(tIDs != NULL, "tIDs");

    dataInput_t* args = malloc(n*sizeof(dataInput_t));
        greska(args != NULL, "args");
        
    for(int i = 0; i<n; i++){
        
        args[i].id = i+1;
        greska_niti(pthread_create(&tIDs[i], NULL, pthreadFunc, &args[i]), "niti");
        
    }
    
    for(int i = 0; i<n; i++){
        
        dataOutput_t*out = NULL;
        
        greska_niti(pthread_join(tIDs[i], (void**)&out), "join");
        
        printf("Thread %d finished. Result: %d\n", i+1, out->result);
        
        free(out);
    }
        
    free(args);
    free(tIDs);
        
exit(EXIT_SUCCESS);
}
