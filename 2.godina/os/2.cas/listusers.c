#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#include <pwd.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define UNUSED(x) ((void)(x))    

int main(int argc, char**argv){
    greska(argc == 1, "argumenti");
    
    UNUSED(argv);
    
    setpwent();
    
    struct passwd* usersInfo;
        
    while( (usersInfo = getpwent())!=NULL){
        
    printf("User name: %s\n", usersInfo->pw_name);
    printf("User id: %d\n", (int)usersInfo->pw_uid);
    printf("Group id: %d\n", (int)usersInfo->pw_gid);
    printf("Other info: %s\n", usersInfo->pw_gecos);
    printf("Directory: %s\n", usersInfo->pw_dir);
    printf("Shell: %s\n", usersInfo->pw_shell);
    printf("Password: %s\n", usersInfo->pw_passwd);
    
    printf("\n***************************************\n");
    }

    endpwent();
    
exit(EXIT_SUCCESS);
}
