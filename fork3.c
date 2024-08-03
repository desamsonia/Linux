#include<stdio.h>
int main()
{

	int p = fork();
	printf("PID = %d\n",p);
	if(p==0)
		printf("from child process\n");
	else printf("from parent process\n");
	return 0;
}
