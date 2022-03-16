#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <grp.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define UNUSED(x) ((void)(x))
    
int main(int argc, char**argv){

    UNUSED(argv);
    
    greska(argc == 1, "argumenti");
    
    struct group* groupsInfo;
        
    setgrent();
    
    while((groupsInfo = getgrent()) != NULL ){
        
    printf("Gruop name: %s\n", groupsInfo->gr_name);
    printf("Gruop gid: %d\n", (int)groupsInfo->gr_gid);
    for(int i = 0; groupsInfo->gr_mem[i] != NULL; i++)
        printf("\t%s\n", groupsInfo->gr_mem[i]);
        
       printf("\n***************************************\n");
    }
    
    endgrent();
exit(EXIT_SUCCESS);
}
