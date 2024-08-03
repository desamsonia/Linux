#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    const char* filename = "soni";
    int fd1, fd2;

    fd1 = open(filename, O_RDONLY);
    if (fd1 == -1)
    {
        perror("Error opening file");
        return 1;
    }

    printf("fd1:%d\n",fd1);
    char ch1;
    read(fd1,&ch1,1);
    printf("ch = %c\n",ch1);
    read(fd1,&ch1,1);
    printf("ch = %c\n",ch1);
    read(fd1,&ch1,1);
    printf("ch = %c\n",ch1);

    fd2 = open(filename, O_RDONLY);
    if (fd2 == -1) 
    {
        perror("Error opening file");
        close(fd1); 
        return 1;
    }

    printf("fd2:%d\n",fd2);
    char ch;
    read(fd2,&ch,1);
    printf("ch = %c\n",ch);
    read(fd1,&ch,1);
    printf("ch =%c\n",ch);

    read(fd2,&ch,1);
    printf("ch = %c\n",ch);

    int fd3 = open(filename,O_RDONLY);
    printf("fd3 = %d\n",fd3);

    printf("process ID:%d\n",getpid());
    sleep(30);
    close(fd1);
    close(fd2);

    return 0;
}
