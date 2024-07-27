#include<stdio.h>
#include<stdarg.h>
#include<signal.h>

int i=0;

void my_isr(int sig)
{
        i++;
        if(i==1)
        {
                printf("alaram at 4se\n");
                alarm(2);
        }
        else if(i==2)
        {
                printf("alarm at 6se\n");
                alarm(4);
        }

        else if(i>2)
        {
                printf("alarm at 10sec\n");
                signal(SIGALRM,SIG_DFL);
                alarm(2);
        }
}


int main(int argc,char **argv)
{
        struct sigaction v;
        v.sa_handler = my_isr;
        sigaction(SIGALRM,&v,NULL);
        //signal(SIGALRM,my_isr);
        printf("dk\n");
        alarm(4);
        printf("ks\n");
        while(1);
}
