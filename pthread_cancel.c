#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void* fun(void *ptr)
{
	printf("Hi...\n");
	pthread_cancel(pthread_self());

	printf("im printing\n");
        printf("hellooo");
	return NULL;
}

int main()
{
	pthread_t tid;

	pthread_create(&tid,NULL,fun,NULL);

	pthread_join(tid,NULL);

	return 0;
}
