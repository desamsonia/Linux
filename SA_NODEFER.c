/* programs that verify the effect of the SA_NODEFER flags
 * SA_NODEFER flag allows the signal to be received again while the signal handler is executing.
 */

#include<stdio.h>
#include<signal.h>

void handler(int sig)
{
	printf("HI,i am siganl:%d\n",sig);
}

int main()
{
	struct sigaction sa;
	sa.sa_handler = handler;
	sa.sa_flags = SA_NODEFER;

	sigemptyset(&sa.sa_mask);

	if(sigaction(SIGQUIT,&sa,NULL) == -1)
		perror("sigaction");

	printf("press ctrl+c to trigger signal\n");

	while(1)
	{
		pause();
	}

	return 0;
}
