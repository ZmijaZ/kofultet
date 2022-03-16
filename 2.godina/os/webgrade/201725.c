#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <ftw.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

int brojaci[7];

int ukupno = 0;

int processFile (const char *fpath, const struct stat*sb, int typeflag, struct FTW *ftwbuf){
    
    typeflag &= FTW_PHYS;
    
    
    switch(S_IFMT & sb->st_mode){
        
        case S_IFREG:
            brojaci[0]++;
            break;
        case S_IFDIR:
            brojaci[1]++;
            break;
        case S_IFCHR:
            brojaci[2]++;
            break;
        case S_IFBLK:
            brojaci[3]++;
            break;
        case S_IFLNK:
            brojaci[4]++;
            break;
        case S_IFIFO:
            brojaci[5]++;
            break;
        case S_IFSOCK:
            brojaci[6]++;
            break;
    }
    
    

}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    for(int i = 0; i<7; i++)
        brojaci[i] = 0;
    
    printf("\nUkupno: %d", ukupno);
    
    greska(nftw(argv[2], processFile, 50, 0)!= -1, "nftw");
    
exit(EXIT_SUCCESS);
}

