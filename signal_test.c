#include<stdio.h>
#include<signal.h>

void my_isr(int sig)
{
  printf("im my_isr = %d\n",sig);
}

int main()
{
        struct sigaction v;
        int num;

//      signal(3,my_isr);
        printf("Enter signal number:");
        scanf("%d",&num);

        //signal(3,SIG_DFL);
        signal(num,SIG_IGN);

        //signal(num,my_isr);
        sigaction(num,0,&v);

        if(v.sa_handler == SIG_DFL)
                printf("Default..\n");

        else if(v.sa_handler == SIG_IGN)
                printf("ignored...\n");

        else
                printf("my isr...\n");
        return 0;
}
