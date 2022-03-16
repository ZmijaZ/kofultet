#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <pwd.h>
#include <grp.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

char* getUserName(uid_t u){
    
    struct passwd* userInfo = getpwuid(u);
        greska(userInfo != NULL, "userInfo");
        
    char* userName = malloc((strlen(userInfo->pw_name)+1)*sizeof(char));
        greska(userName != NULL, "userName");
        
    sprintf(userName, "%s", userInfo->pw_name);
        
    return userName;
    
}

char* getGrName(gid_t g){
    
    struct group* grInfo = getgrgid(g);
        greska(grInfo != NULL, "grInfo");
        
    char* groupName = malloc((strlen(grInfo->gr_name) + 1)*sizeof(char));
        greska(groupName != NULL, "groupName");
        
    sprintf(groupName, "%s", grInfo->gr_name);
        
    return groupName;
}

    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo) != -1, "stat");
        
    printf("%s\n", getUserName(fInfo.st_uid));
    printf("%s\n", getGrName(fInfo.st_gid));
        
exit(EXIT_SUCCESS);
}

