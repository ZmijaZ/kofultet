#define _XOPEN_SOURCE 700
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>

#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#include<errno.h>


#define check_error(cond, userMsg)\
	do{\
		if(!(cond)){\
			perror(userMsg);\
			exit(EXIT_FAILURE);\
		}\
	}while(0)


#define MAX_SIZE (257)



int provera(char *rec) {

    if(!isdigit(rec[0]) && rec[0] != '-')
        return 1;

    for(int i = 1; rec[i]; i++) {
        if(!(isdigit(rec[i])))
            return 1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
	check_error(argc == 2, "arugmenti");

	struct stat fInfo;
	check_error(stat(argv[1], &fInfo) != -1, "ne postojeci fajl");

	int fd = open(argv[1], O_RDWR);
	check_error(fd != -1, "open");


	FILE* f = fdopen(fd,"r+");
	check_error(f != NULL, "fajl strim");


	int zakljucano = 0;
	char buffer[MAX_SIZE];


	while(fscanf(f,"%s",buffer) == 1){

	  if(provera(buffer) == 0) {
            
         	  int n = strlen(buffer);
            long t = ftell(f);
            check_error(t != -1, "1");
            struct flock lock;
            lock.l_type = F_RDLCK;
            lock.l_whence = SEEK_SET;
            lock.l_start = ftell(f);
            lock.l_len = -strlen(buffer);

            int retValue = fcntl(fd, F_SETLK, &lock);
            if(retValue != -1)
            	zakljucano++;

        }

    }
	printf("%d\n",zakljucano);
	exit(EXIT_SUCCESS);
}
