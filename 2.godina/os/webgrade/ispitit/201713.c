#define _XOPEN_SOURCE 700

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>
#include <errno.h>

#define greska(izraz, poruka)\
    do{\
        if(!(izraz)){\
            perror(poruka);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
#define greska_niti(errNum, poruka)\
    do{\
        int _err = errNum;\
        if(_err > 0){\
            errno = _err;\
            greska(0, poruka);\
        }\
    }while(0)    

    
typedef struct{
    
    int id;
    int vrsta;
    
}inputData_t;
    
int m, n;
double globalMin = 0;
double ** matrica;
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;


void * threadFunc(void *arg){
    
    inputData_t* data = (inputData_t*) arg;
    
    double min = matrica[data->vrsta][0];
    for(int i = 0; i<m; i++)
        if(matrica[data->vrsta][i] < min)
            min = matrica[data->vrsta][i];
    
        
    greska_niti(pthread_mutex_lock(&globalLock), "lock");
        if(min < globalMin)
            globalMin = min;
    greska_niti(pthread_mutex_unlock(&globalLock), "unlock");
        
    return NULL;
}
    
int main(int argc, char**argv){
    
    greska(argc == 2, "argumenti");
    
    FILE*f = fopen(argv[2], "r");
        greska(f != NULL, "fopen");
        
    fscanf(f, "%d%d", &n, &m);
    
    matrica = malloc(n*sizeof(double*));
        greska(matrica != NULL, "matrica");
        
    for(int i = 0; i<n; i++){
        matrica[i] = malloc(m*sizeof(double));
        greska(matrica[i] != NULL, "matrica[i]");
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++)
            fscanf(f, "%lf", &matrica[i][j]);
    }
    
    fclose(f);
    
    
    pthread_t *tids = malloc(n*sizeof(pthread_t));
        greska(tids != NULL, "tids");
    inputData_t *args = malloc(n*sizeof(inputData_t));
        greska(args != NULL, "args");
        
    for(int i = 0; i<n; i++){
        args[i].id = i + 1;
        args[i].vrsta = i;
        greska_niti(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create");
    }
    
    for(int i = 0; i<n; i++){
        
        greska_niti(pthread_join(tids[i], NULL), "dasd");
        
    }
    
    printf("%lf\n", globalMin);
    
    for(int i = 0; i < n; i++)
		free(matrica[i]);
	free(matrica);


	free(tids);
	free(args);

    greska_niti(pthread_mutex_destroy(&globalLock), "destroy");
    
exit(EXIT_SUCCESS);
}

