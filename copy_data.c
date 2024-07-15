// copying data from one (file) to another (file), this app display percentage of data copied and time remaining in thread1 and reading data and writing data to another is done in other thread2

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

pthread_t t1,t2;
int flag=0;
unsigned long int l1,count=0;
char file1[30],file2[30];
void *f2(void *t2);

void *f1(void *t1)
{
        while(flag==0);
        float copied_data;
        int time_remaining;
        int fd1,fd2;
        printf("%lu\n",l1);
        while(count==0);
        while(1)
        {

                copied_data=(float)((count*100)/(l1));
                time_remaining=(0.5*(l1-count));
                printf("%f of data copied , %d sec remaning time  c==%lu.\n",copied_data,time_remaining/10,count);
                system("clear");
        if(copied_data==100&&time_remaining==0)
                break;
        }

        printf("data successfully transfered\n");
        pthread_exit(0);
}

void *f2(void *t2)
{
	//int s =400;
        char ch;
        int fd1,fd2;
        fd1=open(file1,O_RDONLY);
        if(fd1<0)
        {
                perror("open");
                exit(0);
        }
        fd2=open(file2,O_CREAT|O_WRONLY,0660);
        if(fd2<0)
        {
                perror("open");
                exit(0);
        }
        l1=lseek(fd1,0,2);
        lseek(fd1,0,0);
        flag=1;
        while(read(fd1,&ch,1))
        {
                write(fd2,&ch,1);
                count++;
                usleep(50000);
        }
        close(fd1);
        close(fd2);
        pthread_exit(0);

}


int main(int argc,char *argv[])
{
        strcpy(file1,argv[1]);
        strcpy(file2,argv[2]);

	pthread_create(&t1,NULL,f1,NULL);
        pthread_create(&t2,NULL,f2,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

        pthread_exit(0);
}
