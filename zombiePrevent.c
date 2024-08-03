// SIGCHLD signal to prevent Zombie processes and also simultaneous execution
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
void func(int signum)
{
	printf("signum = %d\n",signum);
	wait(NULL);
}
int main()
{
	int i;
	int pid = fork();
	if(pid == 0)
	{
		for (i=0; i<20; i++)
		{
			printf("I am Child PID = %d\n",getpid());
			sleep(10);
		}
	}

	else
	{
		signal(SIGCHLD, func);
		printf("I am Parent PID = %d\n",getpid());
		while(1);
	}
}

