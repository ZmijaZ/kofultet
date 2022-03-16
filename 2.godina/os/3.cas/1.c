#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

void dirSize(char*path, unsigned *size){
    struct stat fInfo;
        greska(lstat(path, &fInfo) != -1, "greska");
    
    *size+= fInfo.st_size;
        
    if(!S_ISDIR(fInfo.st_mode))
        return;
    
    DIR*dir = opendir(path);
        greska(dir != NULL, "...");
        
    struct dirent* dirEntry = NULL;
    
    while((dirEntry = readdir(dir)) != NULL){
        
        char* putanja = malloc(sizeof(path) + sizeof(dirEntry->d_name) + 2);
            greska(putanja != NULL, "putanja");
        
        sprintf(putanja, "%s/%s", path, dirEntry->d_name);
        
        if( (!strcmp(dirEntry->d_name, ".")) ||
            (!strcmp(dirEntry->d_name, "..")) ){
            
            greska(stat(putanja, &fInfo) != -1, "...");
            
            *size+= fInfo.st_size;
        
            free(putanja);
            continue;
            }
            dirSize(putanja, size);
            free(putanja);
    }
    greska(closedir(dir) != -1, "...");
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo) != -1, "stat");
        greska(S_ISDIR(fInfo.st_mode), "nije dir");
    
    unsigned size = 0;
    
    dirSize(argv[1], &size);
    
    printf("Velicina je: %uB", size);
    
exit(EXIT_SUCCESS);
}
