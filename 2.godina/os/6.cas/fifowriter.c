#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <errno.h>
#include <time.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

int main(int argc, char** argv){
    
    greska(argc == 2, "argumenti");
    
    struct stat fInfo;
    int retVal = stat(argv[1], &fInfo);
    
    if(retVal == -1){
        //provera da li je greska to sto na putanji nema fajla
        if(errno != ENOENT){
            greska(0, "errno");
            
        }
        //fajl na putanji ne postoji, napravicemo ga
        
        greska(mkfifo(argv[1], 0777) != -1, "...");
    }
    
    int fd = open(argv[1], O_WRONLY | O_TRUNC);
        greska(fd!= -1, "fd");
        
    srand(time(NULL));
    int x;
    char response[30];
    
    do{
        x = rand();
            greska(write(fd, &x, sizeof(int)) != -1, "write");
        printf("Number sent: %d\n", x);
        
        printf("Send next: (yes|no) \n");
        scanf("%s", response);
        
    }while(strcmp(response, "no"));
    
        
    close (fd);
    
    exit(EXIT_SUCCESS);
}
