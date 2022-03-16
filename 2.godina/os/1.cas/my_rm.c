#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
            }\
    }while(0)
    
int main(int argc, char** argv){
    
    greska(argc == 3, "argumenti");
    
    if(strcmp(argv[2], "-f") == 0)
        greska(unlink(argv[1]) != -1, "dd");
    else if(strcmp(argv[2], "-d") == 0)
        greska(rmdir(argv[1]) != -1, "bb");
    else
        greska(0, "pogresna opcija");
    
exit(EXIT_SUCCESS);
}
