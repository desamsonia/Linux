#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* thread1_(void* arg) 
{
    printf("gettid:%ld\n",gettid());
    int lVar = 420;
    int* ptr = (int*)arg;
    *ptr = lVar; 
    printf("Thread1: Local variable = %d\n", lVar);
    return 0;
}

void* thread2_(void* arg)
{
    int* ptr1 = (int*)arg;
    int lVar1 = *ptr1; 
    printf("Thread2: Accessed local variable = %d\n",lVar1);
    return 0;
}

int main() 
{
    pthread_t thread1, thread2;
    int args;
    pthread_create(&thread1, NULL, thread1_, &args);// here 4th arguement is global or heap variable
    printf("tid : %ld\n",(long)thread1);
    pthread_join(thread1, NULL); 
    pthread_create(&thread2, NULL, thread2_, &args);
    pthread_join(thread2, NULL);
    return 0;
}
