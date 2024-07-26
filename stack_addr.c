#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread_function(void* arg)
{
    int local_variable = 42;
    printf("Thread ID %lu: Local variable address = %p\n", pthread_self(), &local_variable);
    return NULL;
}

int main() 
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

