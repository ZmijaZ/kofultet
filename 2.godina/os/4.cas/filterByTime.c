#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

#include <ftw.h>
#include <time.h>


#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
            
time_t now;
    
int processFile(const char* fpath, const struct stat* sb, int typeflag, struct FTW* ftwbuf){
    
    if (typeflag == FTW_F){
        time_t diff = (now - sb->st_mtime) / (24*60*60);
        if(diff < 7)
            printf("%s: %s\n", fpath, fpath + ftwbuf->base);
        
    }
    return 0;
}
    
int main(int argc, char**argv){

    greska(argc == 2, "argumenti");
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo) != -1, "stat");
        greska(S_ISDIR(fInfo.st_mode), "...");
        
    greska(time(&now) != -1, "...");
        
    greska(nftw(argv[1], processFile, 50, 0) != -1, "...");
        
exit(EXIT_SUCCESS);
}
