#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>

void myisr(int n)
{
	printf("in isr %d ---%s\n",n,strsignal(n));
}

int main()
{
	int a[2],b=20;

	pipe(a);
	perror("pipe");

	signal(SIGPIPE,myisr);

	close(a[0]);

	write(a[1],&b,4);
	perror("write");
}
