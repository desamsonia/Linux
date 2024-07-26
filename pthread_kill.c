#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void* myfun()
{
	while(17)
	{
		printf("thread is running...\n");
		sleep(1);
	}
	return NULL;
}

int main()
{
	pthread_t tid;

	pthread_create(&tid,NULL,myfun,NULL);
        
	sleep(3);
	pthread_kill(tid,9);
	perror("pthread_kill");

	pthread_join(tid,NULL);

	return 0;
}
