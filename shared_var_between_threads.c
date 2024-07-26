#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_t tid1,tid2;
static int *ptr = NULL;
int f = 0;

void *thread1()
{
	//printf("i'm thread1:\n");
	while(!f)
	{
	  //sleep(1);
	  *ptr = *ptr + 1;
	  printf("i'm thread1");
          //printf("After Thread 1: localVar = %d\n",*ptr);
	}
       return NULL;
}

void *thread2()
{
       while(!f)
       {
	      //sleep(6);
	       printf("%d",*ptr);
               printf("i'm Thread 2:%d\n",*ptr);
       }
       return NULL;
}

void fun()
{
    int data=39;
    ptr = &data;
    void *s;
    pthread_create(&tid1, NULL, thread1, NULL);
   // pthread_exit(s);
    pthread_create(&tid2, NULL, thread2, NULL);
        
    //return 0;
  //  pthread_join(tid1, NULL);
  //  pthread_join(tid2, NULL);	   
}

int main() 
{
     fun();
     sleep(5);
     f=1;
    return 0;
}
