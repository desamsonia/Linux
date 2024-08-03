#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<fcntl.h>

int main()
{
	struct sembuf v;
	char a[] = "abcdefghijklmnopqr";
	int i,id,fd;

	fd=open("data",O_RDWR|O_CREAT| O_APPEND,0666);

	id = semget(4,5,IPC_CREAT|0666);
	perror("semget");

	v.sem_num = 1;
	v.sem_op = 0;
	v.sem_flg = SEM_UNDO;

	printf("Before\n");
	semop(id,&v,1);

	printf("After\n");
	for(i=0;a[i];i++)
	{
		write(fd,&a[i],1);
		sleep(1);
	}
	printf("Done\n");
	v.sem_num=1;
	v.sem_op=2;
	v.sem_flg=SEM_UNDO;
	printf("Before\n");
	semop(id,&v,1);
	printf("After\n");
}
