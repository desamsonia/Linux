#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static int *s_ptr = NULL;

void* thread_entry(void* arg)
{
    int var = 1000000;
    s_ptr = &var;
    //printf("%d\n",*s_ptr);
    return 0;
}

void* thread_entry_1(void* arg1)
{
	//int v = 345;
//	s_ptr = & var;
	printf("%i",*s_ptr);
	return 0;
}

int main() 
{
    //int a = 10;
   // s_ptr = &a
    pthread_t thread,thread1;
    pthread_create(&thread, NULL, thread_entry, NULL);
    pthread_create(&thread1, NULL, thread_entry_1,NULL);
    sleep(1);
    printf("%d", *s_ptr);
    fflush(stdout);
    pthread_join(thread, NULL);
}
