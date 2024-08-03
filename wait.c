#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
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
		printf("Parent process PID = %d and PPID = %d\n",getpid(),getppid());
		int ret1=fork();
		if(ret1==0)
		{
			printf("child 2 PID = %d and PPID = %d\n",getpid(),getppid());
			sleep(2);
		}
		else
		{
			int pid,status;
			//pid=wait(&status);
			pid=waitpid(ret,&status,WNOHANG);
			printf("child process %d got exited with %d exit status\n",pid,status>>8);
			pid=waitpid(ret,&status,0);
			printf("child process %d got exited with %d exit status\n",pid,status>>8);
		}
	}

	else
	{
		printf("child 1 process PID = %d and PPID = %d\n",getpid(),getppid());
		sleep(3);
		exit(12);
	}
	return 0;
}
