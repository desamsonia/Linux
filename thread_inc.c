#include<pthread.h>
#include<stdio.h>

static int glob = 0;
static void* func(void *arg);

int main(int argc,char *argv[])
{
	pthread_t t1,t2;
	int loop,s;

	loop = (argc > 1) ? 0 : 100;
	s = pthread_create(&t1, NULL, func, &loop);

	if( s != 0)
		perror("pthread_create");
	s = pthread_create(&t2, NULL, func, &loop);

	s = pthread_join(t1, NULL);

	if( s != 0)
		perror("pthread_join");

	s = pthread_join(t2, NULL);

	if(s != 0)
		perror("pthread_join");

	printf("global:%d\n",glob);
	return 0;
}

static void* func(void *arg)
{
	int loop = *((int *)arg);
	int loc,j;

	for(j=0;j<loop;j++)
	{
		loc = glob;
		loc++;
		glob = loc;
	}

//	printf("loc:%d\n",loc);
	printf("glob:%d\n",glob);
        printf("loc:%d\n",loc);
          	return NULL;
}
