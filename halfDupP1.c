#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	int fdr,fdw;
	char a[100],b[100];

	mkfifo("fifohd1",0600);
	mkfifo("fifohd2",0600);

	fdr = open("fifohd1",O_RDWR);
	fdw = open("fifohd2",O_RDWR);

		printf("You...\n");
		scanf("%[^\n]",a);

		write(fdw,a,strlen(a)+1);

		bzero(b,sizeof(b));
		read(fdr,b,sizeof(b));

		printf("\t\tfrom AP\n");
	
}
