#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_key_t key;


void* thread1Func(void* arg) 
{
    int lVar = 420;
    pthread_setspecific(key, &lVar);
    printf("Thread1: Local variable = %d\n",lVar);
    return NULL;
}


void* thread2Func(void* arg)
{
    int* lVarPtr = (int*)pthread_getspecific(key);
    int localVar = *lVarPtr;
    printf("Thread2: Accessed local variable = %d\n", localVar);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_key_create(&key, NULL);

    pthread_create(&thread1, NULL, thread1Func, NULL);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, thread2Func, NULL);
    pthread_join(thread2, NULL);

    pthread_key_delete(key);

    return 0;
}

