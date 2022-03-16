#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <pwd.h>

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
    greska(argc == 2, "argumenti");
    
    struct passwd* userInfo = getpwnam(argv[1]);
        greska(userInfo != NULL, "greska");
        
    printf("User name: %s\n", userInfo->pw_name);
    printf("User id: %d\n", (int)userInfo->pw_uid);
    printf("Group id: %d\n", (int)userInfo->pw_gid);
    printf("Other info: %s\n", userInfo->pw_gecos);
    printf("Directory: %s\n", userInfo->pw_dir);
    printf("Shell: %s\n", userInfo->pw_shell);
    printf("Password: %s\n", userInfo->pw_passwd);
    
exit(EXIT_SUCCESS);
}
