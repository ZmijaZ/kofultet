#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    
#define MAX_SIZE 256
    
int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    FILE*f = fopen(argv[1], "r");
        greska(f != NULL, "open");
    
    char buffer[MAX_SIZE];
    strcpy(buffer, argv[2]);
    
    char rec[MAX_SIZE];
    
    while(fscanf(f, "%s", rec) == 1){
        
        if(strcmp(rec, buffer) == 0){
            
            int lock_type = 0;
            if(!is
        }
        
    }
    
    
exit(EXIT_SUCCESS);
}

