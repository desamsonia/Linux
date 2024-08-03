#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if(argc != 3)
	{
		printf("Incorrect inputs\n");
		exit(0);
	}
	int ret,n,k,i,s;
	pid_t arr[n];
	n=atoi(argv[1]);
	k=atoi(argv[2]);
	for(i=0;i<n;i++)
	{
		ret=fork();
		if(ret==0)
		{
			printf("child %d and PID = %d and PPID = %d\n",i,getpid(),getppid());
			s=rand()%10;
			sleep(s);
			exit(s);
		}
		else
		{
			arr[i]=ret;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	int pid,status;
        pid=waitpid(arr[k],&status,0);
	printf("child %d and PID = %d got exited with status %d\n",k,pid,status>>8);

}
