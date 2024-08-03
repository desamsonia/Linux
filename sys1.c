#include<stdio.h>
int main()
{
	printf("PID = %d,PPID = %d\n",getpid(),getppid());
	while(1);
}
