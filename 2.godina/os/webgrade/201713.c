#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <time.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

unsigned osNumOfDaysFileModified(const char *fpath);
 
time_t now;

int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    unsigned vremeM = osNumOfDaysFileModified(argv[1]);

    now/=(60*60*24);
    
    printf("%u\n", (unsigned)(now-vremeM));

    
exit(EXIT_SUCCESS);
}

unsigned osNumOfDaysFileModified(const char *fpath){
    
    struct stat fInfo;
        greska(stat(fpath, &fInfo) != -1, "stat");
        
    greska(time(&now) != -1, "nowtime");;
        
    unsigned vremeM = (unsigned)fInfo.st_mtime;
        
    return vremeM/(60*60*24);
    
}
