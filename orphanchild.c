#include<stdio.h>
#include<unistd.h>
int main()
{
	if(fork()==0)
	{
		printf("in child before sleep pid = %d ppid = %d\n",getpid(),getppid());
		sleep(10);
		int ret = getppid();
		printf("ret = %d\n",ret);
		printf("in child after sleep pid = %d ppid = %d\n",getpid(),getppid());
	}
	else
	{
		printf("in parent pid = %d ppid = %d\n",getpid(),getppid());
		sleep(5);
	}
	return 0;
}
