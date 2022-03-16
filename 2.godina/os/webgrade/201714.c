#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

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
    
#define MAX_SIZE 1024
    
void osMoveFile(const char *srcPath, const char *destPath);

int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    osMoveFile(argv[1], argv[2]);
    
exit(EXIT_SUCCESS);
}

void osMoveFile(const char *srcPath, const char *destPath)
{
 
    if(strcmp(srcPath, destPath) == 0)
        greska(0, "isti fajl");
    
    struct stat fInfo;
        greska(stat(srcPath, &fInfo) != -1, "stat");
    
    int srcFd = open(srcPath, O_RDONLY);
        greska(srcFd != -1, "srcFd");
        
    int destFd = open(destPath, O_WRONLY | O_TRUNC | O_CREAT, 0777);
        greska(destFd != -1, "destFd");
        
    int readBytes = 0;
    char buffer[MAX_SIZE];
    
    while((readBytes = read(srcFd, buffer, MAX_SIZE)) >0){
        
        greska(write(destFd, buffer, readBytes) != -1, "write");
        
    }
    greska(readBytes != -1, "read");
    
    close(srcFd);
    close(destFd);
    
    greska(unlink(srcPath) != -1, "unlink");
    greska(chmod(destPath, fInfo.st_mode) != -1, "chmod");
}
