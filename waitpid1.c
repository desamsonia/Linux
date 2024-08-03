#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	int r,s,ret;
	printf("In parent....%d\n",getpid());

	if((r==fork())==0)
	{
		printf("In child...%d\n",getpid());
		sleep(40);
	}
	else
	{
		while(1)
		{
			ret=waitpid(r,&s,WNOHANG | WUNTRACED | WCONTINUED);
			if(ret==-1)
				break;
			if(ret==0)
				continue;
			printf("child %d %x\n",s,s);
			sleep(5);
		}
		printf("Out parent...\n");
	}
}
