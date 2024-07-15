#include<stdio.h>
#include<pthread.h>
#include<string.h>

static void *func(void *arg)
{
	char *s = (char *)arg;
	printf("msg:%s",s);
	return (void *)strlen(s);
}

int main()
{
	pthread_t tid;
        void *res;
	int s;
	s = pthread_create(&tid,NULL, func,"Hello world\n");
      
      	if(s != 0)
		perror("pthread_create");

	printf("Message frome main()\n");
	s = pthread_join(tid, &res);
	if(s != 0)
		perror("pthread_join");

	printf("thread returned is:%ld\n",(long)res);
	return 0;
}
