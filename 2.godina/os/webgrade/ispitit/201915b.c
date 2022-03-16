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

#define MAX_SIZE 257    

int provera(char *s){
    
    if(!isdigit(s[0]))
        return -1;
    if(strlen(s) != 4)
        return -1;
    for(int i = 1; i<strlen(s); i++)
        if(!isdigit(s[i]))
            return -1;
        
    return 1;
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    int fd  = open(argv[1], O_RDWR);
        greska(f != -1, "fopen");
        
    FILE*f = fdopen(fd, "r+");
        greska(f != NULL, "f");
        
    char buffer[MAX_SIZE];
    
    while(fscanf(f, "%s", buffer) == 1){
        
        if(provera(buffer)){
            
            long t = ftell(f);
            
            sturct flock lock;
            lock.l_type = F_WRLCK;
            lock.l_whence = SEEK_SET;
            lock.l_start = t;
            lock.l_len = -strlen(buffer);
            
            int retVal = fcntl(
            
        }
        
        
    }
    
exit(EXIT_SUCCESS);
}

