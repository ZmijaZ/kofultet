#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


#include <stdio.h>
#include <stdlib.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int main(int argc, char**argv){
    
    greska(argc == 1, "argumenti");
    
    pid_t childPid = fork();
        greska(childPid!=-1, "childPid");
    
    if(childPid > 0){//parent
        
        printf("Parent: \n\t My ID: %d\n\tChild ID: %d\n", (int)getpid(), (int)childPid);
    }
    
    else{//child
        printf("Child:\n\tMy ID: %d\t\tParent ID: %d\n", (int)getpid(), (int)getppid());
        exit(EXIT_SUCCESS); //samo child, ne i parent
        
    }
    
    printf("Ovo stampaju oba procesa\n");
    
    //cekanje, ceka da se zavrsi child pa odna ispisuje
    int status = 0;
    greska(wait(&status) != -1, "...");
    
    if(WIFEXITED(status)){ // da li es program zavrsio
    
        if(WEXITSTATUS(status)==EXIT_SUCCESS)
            
            printf("Uspeh\n");
        else
            printf("Neuspeh\n");
    }
    else{
        printf("Neuspeh\n");
    }
    printf("Child se zavrsio\n");
    
    exit(EXIT_SUCCESS);
}
