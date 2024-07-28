#include<stdio.h>
#include<signal.h>
#include<stdlib.h>

void print_signal_set(sigset_t *set)
{
	int sig;
        for(sig=1;sig<NSIG;sig++)
        {
                if(sigismember(set,sig))
                {
                        printf("signal %d is in sigset\n",sig);
                }
        }
}

int main()
{
	printf("pid:%d\n",getpid());
	sigset_t set;

	if(sigemptyset(&set) == - 1)
	{
		perror("sigemptyset");
		exit(EXIT_FAILURE);
	}

	if(sigaddset(&set,SIGINT) == -1)
		perror("sigaddset SIGINT");
	if(sigaddset(&set,SIGQUIT) == -1)
		perror("sigaddset SIGQUIT");
	if(sigaddset(&set,SIGUSR1) == -1)
		perror("sigaddset SIGUSR1");

       	if(sigprocmask(SIG_BLOCK, &set, NULL) == -1) 
	{
              perror("sigprocmask");
              exit(EXIT_FAILURE);
          }

	sleep(60);

	if(sigprocmask(SIG_SETMASK, &set, NULL) == -1)
                 exit(EXIT_FAILURE);
	//sleep(10);

	if(sigprocmask(SIG_UNBLOCK, &set, NULL) == -1)
	{
		perror("sigprocmask");
		exit(EXIT_FAILURE);
	}

       print_signal_set(&set);

       if(sigdelset(&set,SIGUSR1) == -1)
	       perror("sigdelset");

       print_signal_set(&set);

       sigset_t pendingSigs;
       if (sigpending(&pendingSigs) == -1)
                 perror("sigpending");

       print_signal_set(&pendingSigs);
       return 0;
}
