//program that demonstrates how to get the previous disposition of a signal using sigaction()

#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void handler(int signum)
{
    printf("Caught signal %d\n", signum);
}

int main()
{
	struct sigaction new, old;
	new.sa_handler = SIG_IGN; // default disposition is SIG_DFL, so new one is SIG_IGN
        new.sa_flags = 0;
	sigemptyset(&new.sa_mask);

	if(sigaction(SIGINT,&new,&old) == -1) // new dispostion is SIG_IGN, old is SIG_DFL
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	if(sigaction(SIGINT,&new,&old) == -1) //old is SIG_IGN, and new also SIG_IGN
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}

	new.sa_handler = handler;  // new is custom handler, old is SIG_IGN

	if(sigaction(SIGINT,&new,&old) == -1)
        {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }

	new.sa_handler = handler; // new is custom handler, old also custom handler

	if(sigaction(SIGINT,&new,&old) == -1)
        {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }

	if(old.sa_handler == SIG_DFL)
		printf("previous dispositon of SIGINT was default action\n");

	else if(old.sa_handler == SIG_IGN)
		printf("previous disposition of SIGINT was ignore action\n");
	else
		printf("previous dispostion of SIGINT was custom handler\n");

	printf("press ctrl+C\n");

	while(1)
	{
		pause();
	}
	return 0;
}
