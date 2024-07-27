// send signal to process using kill() system call
#include<stdio.h>
#include<signal.h>
#include<errno.h>
#include<string.h>

int main(int argc,char *argv[])
{
  int s;
  s=kill(atoi(argv[1]),atoi(argv[2]));

  if(s==0)
          printf("process exits we can send signal to process\n");
  else if(errno == EPERM)
          printf("Process exists, but we don't have " "permission to send it a signal\n");
  else if(errno == ESRCH)
          printf("process does not exit\n");

  return 0;
}
