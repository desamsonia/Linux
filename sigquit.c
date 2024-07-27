#include<stdio.h>
#include<signal.h>

void my_isr(int sig)
{
        printf("signal number = %d\n",sig);
}

int main()
{
        struct sigaction v;
        v.sa_handler = my_isr;
        sigaction(3,&v,NULL);
        while(1);
}
