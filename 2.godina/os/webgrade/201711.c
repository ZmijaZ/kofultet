#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

bool osIsPublicFile(const char *fpath);
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    if(osIsPublicFile(argv[1]))
        printf("true\n");
    else
        printf("false\n");
    
    
exit(EXIT_SUCCESS);
}

bool osIsPublicFile(const char *fpath){
        
    struct stat fInfo;
        greska(stat(fpath, &fInfo) != -1, "stat");
        
    greska(!S_ISDIR(fInfo.st_mode), "dir je");
    
    if( (S_IROTH & fInfo.st_mode) && (S_IWOTH & fInfo.st_mode))
        return true;
    else
        return false;
    
    
}
