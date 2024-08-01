#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a[2];
	if(pipe(a) == -1)
	{
	    perror("pipe");
	    exit(0);
	}

	int ret = fork();
	if(ret)
	{
		close(a[0]); // read end closed
	        char str[100] = "King of my heart !!q";
		if(write(a[1],str,strlen(str)) == strlen(str))
			printf("success\n");
	}

	else
	{
		char ch;
		close(a[1]);//write end closed
            while(1)
	    {

	        if(read(a[0],&ch,1) < 1)
		{
			perror("read");
			exit(0);
		}

		else
		{
			if(ch=='q')
				break;
			printf("%c",ch);
		}
	    }

	    printf("\n");
	}
}
