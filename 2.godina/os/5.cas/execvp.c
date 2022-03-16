#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

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
    
int main(int argc, char**argv){    

    
    //gcc -std=c99 exec.o -o exec
    //char**niz = ["gcc",  "-std=c99",  "exec.o",  "-o", "exec"];
    //execvp(niz[0], niz);
    
    char**niz = malloc(argc*sizeof(char*));
        greska(niz != NULL, "malloc");
        
    for(int i = 0; i<argc; i++){
        niz[i-1] = malloc(strlen(argv[i]) + 1);
            greska(niz[i-1] != NULL, "...");
        strcpy(niz[i-1], argv[i]);
        
    }
    niz[argc-1] = NULL;
    
    pid_t childPid = fork();
        greska(childPid != -1, "fork");
        
    
    if(childPid == 0){
        
        greska(execvp(niz[0], niz) != -1, "...");
        exit(EXIT_FAILURE);
    }
    
    int status = 0;
        greska(wait(&status) != -1, "...");
        
    if(WIFEXITED(status) && (WEXITSTATUS(status) == EXIT_SUCCESS) )
        printf("Uspeh\n");
    else
        printf("Neuspeh\n");
    

    
    exit(EXIT_SUCCESS);
}
