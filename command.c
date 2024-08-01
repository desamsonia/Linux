#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
main()
{
	int a[2];
	if(pipe(a)==-1)
	{
		perror("pipe");
		exit(0);
	}
	
	int ret=fork();

	if(ret==-1)
	{
		perror("fork");
		exit(0);
	}

	if(ret)
	{//exclusive parent code
	 //(writes on to the pipe)
	 	close(a[0]);//read end of the pipe is closed
		dup2(a[1],1);//a[1] & 1 are referring to the write end of the pipe
		//close(1);
		//dup(a[1);
		execlp("ls","ls","-l",NULL);
	}
	else
	{//exclusive child code
	 //reads from the pipe
	 	 close(a[1]);//write end of the pipe is closed
		dup2(a[0],0);//0 & a[0] are referring to the read end of the pipe      
		execlp("wc","wc","-l",NULL);
	}
}

