//WAP to terminate the parent process only after it's three children's processes gets terminated

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

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
		 
		printf("I am in child 2 process with PID=%d PPId=%d\n",getpid(),getppid());
			sleep(2);
			exit(11);
		}

		int ret2=fork();
		if(ret==-1)
		{
			perror("fork3");
			exit(0);
		}

		if(ret2==0)
		{
			printf("im in child 3 process with PID = %d PPID = %d\n",getpid(),getppid());
			sleep(2);
			exit(12);
		}

		else
		{//parent code
		 int status,pid; 
		 //pid=waitpid(ret,&status,0);
		 pid=wait(&status);
		 printf("The child process %d got exited with %d exit status\n",pid,status>>8);

		 int status1,pid1;
		 //pid1=waitpid(ret1,&status,0);
		 pid1=wait(&status1);
		 printf("the cheild process %d got exited with %d exit status\n",pid1,status1>>8);

		 int status2,pid2;
		 //pid2=waitpid(ret2,&status,0);
		 pid2=wait(&status2);
		 printf("the child procees %d got exited with %d exit status\n",pid2,status2>>8);
		}
	}
	else
	{
		printf("I am in child 1 process with PID=%d PPId=%d\n",getpid(),getppid());
		sleep(3);
		exit(10);
	}

}

