#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)

void obradi(char*s){
    
    int n = (int)strlen(s);
    
    char *string = malloc(strlen(s)*sizeof(char));
        greska(string != NULL, "malloc");
    
    for(int i = n-1; i>=0; i--){
        if(s[i] == '/'){
            for(i = i+1; i<n; i++)
                string[i] = s[i];
            break;
        }
    }
    
    printf("%s", string);
    
    return;
}
    
int main(int argc, char**argv){
    
    greska(argc == 3, "argumenti");
    
    struct stat fInfo;
        greska(stat(argv[1], &fInfo) != -1, "stat");
    
    double size = fInfo.st_size;
        
    if(strcmp(argv[2], "KB") == 0){
            
        size/=1024;
        size = (int)ceil(size);
       
        if(strchr(argv[1], '/'))
            obradi(argv[1]);
        else
            printf("%s ", argv[1]);
        
        printf("%dKB\n", (int)size);
        
    }
    
    else if(strcmp(argv[2], "MB") == 0){
            
        size/=1024;
        size/=1024;
        size = (int)ceil(size);
        
        if(strchr(argv[1], '/'))
            obradi(argv[1]);
        else
            printf("%s ", argv[1]);
        
        
 
        printf("%dMB\n", (int)size);
        
    }
    
    else if(strcmp(argv[2], "GB") == 0){
            
        size/=1024;
        size/=1024;
        size/=1024;
        size = (int)ceil(size);
        
         if(strchr(argv[1], '/'))
            obradi(argv[1]);
        else
            printf("%s ", argv[1]);
        
        printf("%dGB\n", (int)size);
        
    }
    else
        greska(0, "pogresan");
        
exit(EXIT_SUCCESS);
}

