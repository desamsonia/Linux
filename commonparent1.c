#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

main()
{
	int ret=fork();
	if(ret==-1)
	{
		perror("fork");
		exit(0);
	}
	if(ret)
	{
		printf("I am in parent process with PID=%d PPId=%d\n",getpid(),getppid());
		int ret1=fork();
		if(ret1==-1)
		{
			perror("fork2");
			exit(0);
		}
		if(ret1==0)
		{//exclusive child2 code
		 
		printf("I am in child2 process with PID=%d PPId=%d\n",getpid(),getppid());
		}
	}
	else
	{
		printf("I am in child process with PID=%d PPId=%d\n",getpid(),getppid());
		//while(1);
	}
}

