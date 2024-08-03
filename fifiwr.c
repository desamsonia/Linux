#include <stdio.h>
#include <string.h>

#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char str[10];
	int fd;
	int n;
	n = mkfifo("fifo1",0666);

	fd=open("fifo1",O_WRONLY);

	if(fd == -1)
	{
		perror("open");
		exit(0);
	}

	do
	{
		scanf("%s",str);
		write(fd,str,strlen(str)+1);

	}while(strcmp(str,"quit"));
	close(fd);
}
