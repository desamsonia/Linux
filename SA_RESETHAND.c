/* program that verify the effect of the SA_RESETHAND flag
 * SA_RESETHAND flag resets the signal handler to the default action after the signal is delivered.
 */

#include<stdio.h>
#include<signal.h>


void handler(int sig)
{
	printf("hii im sinal:%d\n",sig);
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sa.sa_flags = SA_RESETHAND;

	sigemptyset(&sa.sa_mask);

	if(sigaction(SIGINT,&sa,NULL) == -1)
		perror("sigaction");

	printf("press to trigger signal\n");

	while(1)
	{
		pause();
	}

	return 0;
}

