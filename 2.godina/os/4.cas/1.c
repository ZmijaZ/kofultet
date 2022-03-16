#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <ftw.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
            
char*Ext = NULL;

int processFile(const char* fpath, const struct stat *sb, int typeflag, struct FTW* ftwbuf){
    
    if(S_ISREG(sb->st_mode)){
        char*ime = fpath + ftwbuf->base;
        char*ext = strrchr(ime, '.');
        
        if(ext != NULL){
            if(strcmp(ext, Ext) == 0)
                printf("%s: %s\n", fpath, fpath +ftwbuf->base);
        }
        
    }
    return 0;
}
    
int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    Ext = argv[2];
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo), "stat");
        greska(S_ISDIR(fInfo.st_mode), "nije dir");
    
    nftw(argv[1], processFile, 50, 0);
    
exit(EXIT_SUCCESS);
}
