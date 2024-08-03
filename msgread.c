#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct msgbuf
{
	long mtype;
	char data[20];
};

int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("Usage:./rcv msgtype\n");
		return;
	}

	struct msgbuf v;
	int id;
	id=msgget(1,IPC_CREAT|0660);
	if(id<0)
	{
		perror("msgget");
		return ;
	}
	msgrcv(id,&v,sizeof(v.data),atoi(argv[1]),0);

	perror("msgget");
	printf("data: %s\n",v.data);
}
