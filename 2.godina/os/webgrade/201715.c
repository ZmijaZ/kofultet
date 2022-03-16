#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>
#include <time.h>
#include <ftw.h>

#define greska(izraz, poruka)\
    do{\
    if(!(izraz)){\
        perror(poruka);\
        exit(EXIT_FAILURE);\
        }\
    }while(0)

#define MAX_SIZE 1024
    
time_t now;
    
char* destPath;

bool pravaPristupa(const char*path){
    
    struct stat fInfo;  
        greska(stat(path, &fInfo) != -1, "stat");
        greska(!S_ISDIR(fInfo.st_mode), "dir je");
        
    if( (S_IWOTH & fInfo.st_mode) && (S_IROTH & fInfo.st_mode) )
        return true;
    else
        return false;
    
    
}

void myMkdir(const char*path){
   
    mode_t stariUmask = umask(0);
    
    int fd = mkdir(path, 0777);
        greska(fd != -1, "mkdir");
        
    umask(stariUmask);
    
    return;
}

unsigned vremeMod(const char* path){
    
    greska(time(&now) != -1, "now");
    
    struct stat fInfo;
        greska(stat(path, &fInfo) != -1, "stat");
        
    unsigned sad = (unsigned)now / (60*60/24);
    
    unsigned vremeM = fInfo.st_mtime;
    vremeM = (unsigned)vremeM / (60*60*24);
    
    return sad - vremeM;
}

void myMv(const char* srcPath, const char* destPath){
    
    struct stat fInfo;
        greska(stat(srcPath, &fInfo) != -1, "stat");
        
    int srcFd = open(srcPath, O_RDONLY);
        greska(srcFd != -1, "srcFd");
    int destFd = open(destPath, O_WRONLY | O_TRUNC | O_CREAT, 0777);
        greska(destFd != -1, "destFd");
        
    int readBytes = 0;
    char buffer[MAX_SIZE];
        
    while( (readBytes = read(srcFd, buffer, MAX_SIZE)) > 0){
        
        greska(write(destFd, buffer, readBytes) != -1, "write");
        
    }
    
    greska(readBytes != -1, "readBytes");
    
    greska(unlink(srcPath) != -1, "unlink");
    greska(chmod(destPath, fInfo.st_mode) != -1, "chmod");
    
}

int processFile(const char *path, const struct stat *sb, int typeflag, struct FTW* ftwbuf){
    
    (void)typeflag;
    
    if(S_ISREG(sb->st_mode)){
        if(vremeMod(path) <= 30){
            char* fileName = path + ftwbuf->base;
            char* newPath = malloc(strlen(destPath) + 2 + strlen(fileName));
                greska(newPath != NULL, "newPath");
            
            sprintf(newPath, "%s/%s", destPath, filename);
            
            int srcFd = open(path, O_RDONLY);
                greska(srcFd != -1, "srcFd");
            
            int destFd = open(newPath, O_WRONLY | O_CREAT | O_TRUNC, sb->st_mode);
                greska(destFd != -1, "destFd");
                
            
                
        }
        
        
    }
    
    return 0;
}

int main(int argc, char** argv){
        
    greska(argc == 1, "argumenti");
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo) != -1, "stat1");
        greska(S_ISDIR(fInfo.st_mode), "dir1");
        
    struct stat fInfo;
        greska(stat(argv[2], &fInfo) != -1, "stat2");
        greska(S_ISDIR(fInfo.st_mode), "dir2");
    
    destPath = argv[2];
    
    greska(nftw() != -1, "nftw");
        
    exit(EXIT_SUCCESS);
}
