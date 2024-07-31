#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char *argv[])
{
	off_t curr;
	int arr[1000],n=5;
    int f_write = open("start.txt", O_RDONLY);
    int f_read = open("end.txt", O_WRONLY);
    int count = 0;

    curr = lseek(f_write, n, SEEK_CUR);
    curr = lseek(f_write, 2, SEEK_CUR);
    printf("current offset: %ld\n",curr);
    write(f_read, arr, 1);
    count = n;
    
    close(f_write);
    close(f_read);
}
