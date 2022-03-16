#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

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
    
#define MAX_SIZE(2048)
    
void fileinfo(char*path, char**s){
    
    greska(*s == NULL, "string je vec inicijalizovan");
    
    char* buffer = malloc(MAX_SIZE*sizeof(char));
        greska(buffer != NULL, "bafer");
    s*= buffer;
    
    struct stat fInfo;
        greska(stat(path, &fInfo) !=-1, "....");
        
    char pravaPristupa[11]'
    strcpy(pravaPristupa, "-rwxrwxrwx");
    
    switch (fInfo.st_mode & S_IFMT){
        
        case S_IFREG:
            pravaPristupa[0] = '-';
        case S_IFDIR:
            pravaPristupa[0] = 'd';
        case S_IFCHR:
            pravaPristupa[0] = 'c';
        case S_IFBLK:
            pravaPristupa[0] = 'b';
        case S_IFLNK:
            pravaPristupa[0] = 'l';
        case S_IFIFO:
            pravaPristupa[0] = 'f';
        case S_IFSOCK:
            pravaPristupa[0] = 's';

    }
    
    if(! (fInfo.st_mode & S_IRUSR)) //negacija je jer sta cemo ako nemamo prava citanja 
        pravaPristupa[1] = '-';
    if(! (fInfo.st_mode & S_IWUSR))//negacija je jer sta cemo ako nemamo prava pisanja 
        pravaPristupa[2] = '-';/
    if(! (fInfo.st_mode & S_IXUSR)) //negacija je jer sta cemo ako nemamo prava exekjutovanja
        pravaPristupa[3] = '-';
    
    if(! (fInfo.st_mode & S_IRGPR))
        pravaPristupa[4] = '-';
    if(! (fInfo.st_mode & S_IWGPR))
        pravaPristupa[5] = '-';
    if(! (fInfo.st_mode & S_IXGPR))
        pravaPristupa[6] = '-';
    
    if(! (fInfo.st_mode & S_IROTH))
        pravaPristupa[7] = '-';
    if(! (fInfo.st_mode & S_IWOTH))
        pravaPristupa[8] = '-';
    if(! (fInfo.st_mode & S_IXOTH))
        pravaPristupa[9] = '-';
    
    sprintf(buffer, "%s ", pravaPristupa);
    
}
    
int main(int argc, char**argv){

    greska(argumenti == 2, "argumenti");
    
    char*s = NULL;
    fileinfo(argv[1], &s);
    
    printf("%s\n", s);
    
    free(s);
    
exit(EXIT_SUCCESS);
}
