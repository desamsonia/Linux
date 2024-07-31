#include<sys/file.h>
#include <fcntl.h>
#include "curr_time.h"
#include <stdio.h>
#include <errno.h>

int main(int argc,char *argv[])
{
	int fd,lock;
	const char *lname;

	lock = ( argv[2][0] == 's') ? LOCK_SH : LOCK_EX;

	if(argv[2][0] == 'n')
		lock = lock | LOCK_NB;

	fd = open(argv[1],O_RDONLY);
	if(fd == -1)
		perror("open");

	lname = (lock & LOCK_SH) ? "LOCK_SH" : "LOCK_EX";

	printf("PID:%d requesting %s at %s\n", getpid(), lname, currTime("%T"));

	if(flock(fd,lock) == -1)
	{
		if (errno == EWOULDBLOCK)
                            printf("PID %ld: already locked - bye!", (long) getpid());
                 else
                      printf("flock (PID=%ld)", (long) getpid());
	}

       printf("PID %ld: granted %s at %s\n", (long) getpid(), lname,
 currTime("%T"));

       sleep( ((argc > 3)) ? 10 : 10) ;
       //sleep(atoi(argv[3]));

       printf("PID %ld: releasing %s at %s\n", (long) getpid(), lname,
 currTime("%T"));

       if(flock(fd, LOCK_UN) == -1)
	       perror("flock");

       return 0;
}
