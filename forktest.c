#include <stdio.h> 
#include <unistd.h> 
int main() 
{ 
	int p;
	p=fork();
	printf("--%d",p);
	if (fork() || fork()) 
	{
		//printf("p=%d\n",p);
		fork(); 
	}
	printf("1 "); 
	return 0; 
} 

