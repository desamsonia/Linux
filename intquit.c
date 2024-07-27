#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

static void sighandler(int sig)
{
        static int cnt = 0;

        if(sig == SIGINT)
        {
                cnt++;
                printf("caugth SIGINT(%d)\n",cnt);
                return ;
        }

        printf("caugth SIGQUIT - bye !!\n");
        exit(EXIT_SUCCESS);
}

int main()
{
        printf("pid:%d\n",getpid());
        if(signal(SIGINT,sighandler) == SIG_ERR)
                perror("signal");
        if(signal(SIGQUIT,sighandler) == SIG_ERR)
                perror("signal");
        for(;;)
                pause();  // pause/block the process until signal is caught
        return 0;
}
