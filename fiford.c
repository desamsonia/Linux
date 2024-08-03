#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int fd;
	int i;
	char str[10];
        fd = open("fifo1",O_RDONLY);

	printf("fifo opened for reading:\n");

	do
	{
		for(i=0;;i++)
		{
			read(fd,&str[i],1);
			if(str[i] =='\0')
				break;
		}
		printf("%s\n",str);

	}while(strcmp(str,"quit"));

	close(fd);
}
