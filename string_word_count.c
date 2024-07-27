/* read string dynamically, then count no of words in string, if words are less than 5 then sent signal and print invalid inside handler function, 
if greater than 5 then print word count */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

char *getString()
{
        char *str = NULL;
        int i=0;
        do
        {
                str=realloc(str,i+1);
                str[i]=getchar();
        } while(str[i++] != '\n');

        str[--i] ='\0';
        return str;
}

int countWords(char *str)
{
        int cnt = 0;
        while(str=strchr(str,' '))
        {
                cnt++;
                str++;
        }
        return cnt+1;
}
void my_hand(int sig)
{
        printf("signal number: %d\n",sig);
        printf("Invalid\n");
}

int main()
{
        char *str = NULL;
        int cnt;
input:  str = getString();
        cnt = countWords(str);
        printf("count = %d\n",cnt);
        if(cnt<5)
        {
                signal(12,my_hand);
                //signal(10,my_hand);
                //kill(getpid(),10);
                //raise(10);
                raise(12);
                goto input;
        }
}
