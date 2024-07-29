// program child not to become zombie using SA_NOCLDWAIT flag

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void handler(int sig)
{
	printf("Hi,i am signal:%d\n",sig);
}

int main()
{

	struct sigaction sa;
	sa.sa_handler = handler;
	sa.sa_flags = SA_NOCLDWAIT;

	sigemptyset(&sa.sa_mask);

	if(sigaction(SIGCHLD,&sa,NULL) == -1)
		perror("sigaction");

	pid_t pid = fork();

	if(pid  == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	else if(pid == 0)
	{
		printf("child process exiting:%d\n",getpid());
		exit(EXIT_SUCCESS);
	}

	else
	{
		printf("parent process waiting for child to exit:%d\n",getpid());
		sleep(200);
		printf("parent process (PID:%d) finished watiting\n",getpid());
	}

	return 0;
}

