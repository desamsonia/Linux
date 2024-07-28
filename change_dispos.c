#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int signum) 
{
    printf("Caught signal %d\n", signum);
}

int main() 
{
    signal(SIGINT, signal_handler);
    raise(SIGINT);
    // Change the disposition of SIGINT to SIG_IGN
    signal(SIGINT, SIG_IGN);
    
    // Send SIGINT to the current process again
    raise(SIGINT);

    printf("SIGINT ignored\n");

    return 0;
}

