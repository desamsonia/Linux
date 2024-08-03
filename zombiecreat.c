//zombie creation

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
	{//exclusive parent code
		printf("I am in parent process with PID=%d PPId=%d\n",getpid(),getppid());
		sleep(20);
	}
	else
	{//exclusive child code
		printf("I am in child process with PID=%d PPId=%d\n",getpid(),getppid());
	}
}

