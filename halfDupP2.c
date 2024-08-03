#include<stdio.h>
#include<string.h>
#include<fcntl.h>

int main()
{
	int fdr,fdw;
	char a[100],b[100];

	fdr = open("fifohd2",O_RDWR);
	fdw = open("fifohd1",O_RDWR);


		bzero(b,sizeof(b));

		read(fdr,b,sizeof(b));

		printf("\nFrome TS\n %s\n",b);

		printf("You..\n");
		scanf("%[^\n]",a);

		write(fdw,a,strlen(a)+1);
	
}
