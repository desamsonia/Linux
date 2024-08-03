#include<stdio.h>
#include<stdarg.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main(int argc,char *argv[])
{
  int id;
  if(argc != 2)
  {
	  printf("Usage: ./.out keyno\n");
	  return;
  }

  id = msgget(atoi(argv[1]),IPC_CREAT|0666);
  
  if(id<0)
  {
	  perror("msgget");
	  return;
  }

  printf("id = %d\n",id);
}
