#include<signal.h>
#include<stdio.h>
#include "signal_fun.h"


static int sigcnt[NSIG];
static volatile sig_atomic_t gotSigint = 0;

static void handler(int sig)
{
	if(sig == SIGINT)
		gotSigint = 1;
	else
		sigcnt[sig]++;
}

int main(int argc,char *argv[])
{
	int n,numsec;
	sigset_t pendingMask, blockMask, emptyMask;

	printf("%s: PID is %d\n",argv[0], getpid());

	for(n = 1; n < NSIG; n++)
		(void) signal(n,handler);

	if(argc > 1)
	{

	numsec = atoi(argv[1]);

	sigfillset(&blockMask);

	if(sigprocmask(SIG_SETMASK, &blockMask, NULL) == -1)
		perror("sigprocmask1");

	printf("%s: sleeping for %d seconds\n",argv[0],numsec);
	sleep(numsec);

	if(sigpending(&pendingMask) == -1)
		perror("sigpending");

	printf("%s: pending signals are: \n",argv[0]);
	printSigset(stdout,"\t\t", &pendingMask);

	sigemptyset(&emptyMask);
	if(sigprocmask(SIG_UNBLOCK, &emptyMask, NULL) == -1)
		perror("sigprocmask2");
	}

	while(!gotSigint)
		continue;

	for(n = 1; n<NSIG ; n++)
		if(sigcnt != 0)
			printf("%s: signal %d caught %d times%s\n", argv[0],n,sigcnt[n], (sigcnt[n] == 1) ? "": "s");
	return 0;
}
