#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/syscall.h>
#include<math.h>

int arr[10],flag =0;

int checkPrime(int n)
{
  int i;
  for(i=2;i<n;i++)
     if(n%i == 0)
             return 0;
  return 1;
}

void *thread_task1(void *args)
{
printf("hi i'm task1 \n");
printf("Thread1 ID = %d\n",gettid());
int i;
        //while(flag!=0);       //for synchronization
        for(i=0;i<10;i++)
        {
          arr[i] = rand()%89;   //read using rand function
        }
        for(i=0;i<10;i++)
        {
          printf("%d ",arr[i]);
                                //print the elements
        }
        //flag=1;
        pthread_exit(1);
//sleep(30);
}

void *thread_task2(void *args)
{
printf("hi i'm task2 \n");
printf("Thread2 ID = %d\n",gettid());
        //while(flag==0);for synchronization
        printf("\n the prime numbers are\n");
        for(int i=0;i<10;i++)
        {
             if(checkPrime(arr[i]))
               printf("%d ",arr[i]);
                                //check element is prime or not
        }
        pthread_exit(0);
}

void *thread_task3(void *args)
{
        printf("hi im task3\n");
        printf("Thread3 ID = %d\n",gettid());
        int min,max,i,j;
        //while(flag==0);               //for synchroniz
        for(i=0;i<10;i++)
        {
                for(j=i+1;j<10;j++)
                {
                        if(arr[i] > arr[j])
                        {
                                int temp = arr[i];
                                arr[i] = arr[j];
                                arr[j] = temp;
                        }
                }
        }
        printf("After sorting:\n");
        for(i=0;i<10;i++)
                printf("%d ",arr[i]);
        printf("\nhighest number = %d\n",arr[9]);
        printf("smallest number = %d\n",arr[0]);
        pthread_exit(0);
}

int main()
{

pthread_t t_id1,t_id2,t_id3;
printf("process id is %d\n",getpid());
int ret1,ret2,ret3;

ret1=pthread_create(&t_id1,NULL,thread_task1,NULL);
ret2=pthread_create(&t_id2,NULL,thread_task2,NULL);
ret3=pthread_create(&t_id3,NULL,thread_task3,NULL);

if(ret1==0 && ret2==0 && ret3==0)
     printf("thread1, thread2 and thread3 created successfully\n");
else
    printf("unable to creat threads\n");

pthread_join(t_id1,NULL);
pthread_join(t_id2,NULL);
pthread_join(t_id3,NULL);
printf("terminated \n");
return 0;
}
