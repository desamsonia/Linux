//Implementation of siginterrupt() using sigaction 

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

int siginterrupt(int sig,int flag)
{
	struct sigaction act;

	if(sigaction(sig,NULL,&act)==-1)
	{
		perror("sigaction");
		return -1;
	}

	if(flag)
		act.sa_flags  &=  ~ SA_RESTART;
	
	else
		act.sa_flags |= SA_RESTART;

	if(sigaction(sig,&act,NULL) == -1)
	{
		perror("sigaction");
		return -1;
	}
	return 0;
}

void handler(int signum) 
{
    printf("Caught signal %d\n", signum);
}

int main()
{
	struct sigaction sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;

	sigemptyset(&sa.sa_mask);

	if(sigaction(SIGINT,&sa,NULL) == -1)
		perror("sigaction");

	if(siginterrupt(SIGINT,1) == -1)
		perror("siginterrupt");

	printf("press ctrl+c to trigger signal\n");

	while(1)
	{
		pause();
	}

	return 0;
}
