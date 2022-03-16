#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <dirent.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

void dirSize (char* path, unsigned *size);
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    unsigned size = 0;
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo) != -1, "stat1");
    
    if(!S_ISDIR(fInfo.st_mode))
        greska(0, "nije dir");
        
    dirSize(argv[1], &size);
    
    printf("Dir size: %uB\n", size);
        
    exit(EXIT_SUCCESS);
}

void dirSize (char* path, unsigned *size){
    
    struct stat fInfo;
        greska(lstat(path, &fInfo) != -1, "lstat");
        
    *size += fInfo.st_size;
    
    if(!S_ISDIR(fInfo.st_size))
        return;
    
    DIR*dir = opendir(path);
        greska(dir != NULL, "opendir");
    
    struct dirent *dirUlazak = NULL;
    
    while( (dirUlazak = readdir(dir)) != NULL ){
        
        char*putanja = malloc(sizeof(path) + 1 + sizeof(dirUlazak->d_name) + 1);
            greska(putanja != NULL, "malloc");
        
        sprintf(putanja, "%s/%s", path, dirUlazak->d_name);
            
        if(!strcmp(dirUlazak->d_name, ".") && !strcmp(dirUlazak->d_name, "..") ){
            
            greska(stat(putanja, &fInfo) != -1, "stat2");
            
            *size += fInfo.st_size;
            
            free(putanja);
            continue;
        }
        
        dirSize(putanja, size);
        free(putanja);
        
    }
    greska(closedir(dir) != -1, "closedir");
}

