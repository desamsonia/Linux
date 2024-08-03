#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int ret=fork();
	if(ret==-1)
	{
		perror("fork");
		exit(0);
	}
	if(ret)
	{
		printf("im from parent process PID = %d and PPID = %d\n",getpid(),getppid());
		int ret1=fork();

		if(ret1==0)
		{
			printf("im child 2 and my PID = %d and my PPID = %d\n",getpid(),getppid());
		}

	}

        else
	{
		printf("im from child process PID = %d and PPID = %d\n",getpid(),getppid());
	}
	return 0;
}
