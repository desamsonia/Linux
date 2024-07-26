#include<stdio.h>
#include<pthread.h>

int g;

void *fun()
{
	int id = getpid();
	static int s;

	s+=2;
	g+=3;

	printf("Thread id:%d, static:%d, global:%d\n",id,s,g);
}

int main()
{
	pthread_t tid;

	int i;
	for(i=0;i<4;i++)
	{
		pthread_create(&tid,NULL,fun,NULL);
	}
	pthread_exit(NULL);
	return 0;

}


