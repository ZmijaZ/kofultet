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
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    struct group* groupInfo = getgrnam(argv[1]);
        greska(groupInfo != NULL, "greska");
        
    printf("Gruop name: %s\n", groupInfo->gr_name);
    printf("Gruop gid: %d\n", (int)groupInfo->gr_gid);
    for(int i = 0; groupInfo->gr_mem[i] != NULL; i++)
        printf("\t%s\n", groupInfo->gr_mem[i]);
    
    

exit(EXIT_SUCCESS);
}
