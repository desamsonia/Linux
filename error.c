// All threads functions return zero on success and positive values on error

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *myThread(void *arg)
{    
    return NULL;
}

int main() {
    pthread_t tid;
    int result;

    result = pthread_create(&tid, NULL, myThread, NULL);

    if (result != 0) 
    {
        printf("Thread creation failed! Error code: %d\n", result);
        return 1;  
    }

    printf("Thread created successfully.\n");

    pthread_join(tid, NULL);

    return 0;
}


