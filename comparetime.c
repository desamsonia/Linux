#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	struct stat  buf1,buf2;

	stat(argv[1],&buf1);
	stat(argv[2],&buf2);

	if(buf1.st_mtime > buf2.st_mtime)
		printf("%s is new than %s\n",argv[1],argv[2]);
	else
		printf("%s is older than %s\n",argv[1],argv[2]);

}
