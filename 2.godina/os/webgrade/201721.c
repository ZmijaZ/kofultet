#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

#define MAX_SIZE 1024
    
void fileInfo(char*path, char**s){
    
    greska(*s == NULL, "string");
    
    char* buffer = malloc(MAX_SIZE*sizeof(char));
        greska(buffer != NULL, "buffer");
    
    *s = buffer;
    
    struct stat fInfo;
        greska(stat(path, &fInfo) != -1, "stat");
        
    char pravaPristupa[11];
    sprintf(pravaPristupa, "-rwxrwxrwx");
        
    switch(fInfo.st_mode & S_IFMT){
        
        case S_IFREG:
            pravaPristupa[0] = '-';
            break;
        case S_IFCHR:
            pravaPristupa[0] = 'c';
            break;
        case S_IFDIR:
            pravaPristupa[0] = 'd';
            break;
        case S_IFBLK:
            pravaPristupa[0] = 'b';
            break;
        case S_IFLNK:
            pravaPristupa[0] = 'l';
            break;
        case S_IFSOCK:
            pravaPristupa[0] = 's';
            break;
        case S_IFIFO:
            pravaPristupa[0] = 'p';
            break;
    }
    
    if(!(fInfo.st_mode & S_IRUSR))
        pravaPristupa[1] = '-';
    if(!(fInfo.st_mode & S_IWUSR))
        pravaPristupa[2] = '-';
    if(!(fInfo.st_mode & S_IXUSR))
        pravaPristupa[3] = '-';
    
    if(!(fInfo.st_mode & S_IRGRP))
        pravaPristupa[4] = '-';
    if(!(fInfo.st_mode & S_IWGRP))
        pravaPristupa[5] = '-';
    if(!(fInfo.st_mode & S_IXGRP))
        pravaPristupa[6] = '-';
    
    if(!(fInfo.st_mode & S_IROTH))
        pravaPristupa[7] = '-';
    if(!(fInfo.st_mode & S_IWOTH))
        pravaPristupa[8] = '-';
    if(!(fInfo.st_mode & S_IXOTH))
        pravaPristupa[9] = '-';
 
    sprintf(buffer, "%s", pravaPristupa);
    
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    char*s = NULL;
    
    fileInfo(argv[1], &s);
    
    printf("%s\n", s);
    
exit(EXIT_SUCCESS);
}

