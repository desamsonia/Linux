#include <stdio.h>
#include <mqueue.h>

int main() {
    mqd_t queue = mq_open("", O_RDONLY); // Open an existing queue
    if (queue == (mqd_t)-1) {
        perror("mq_open");
        return 1;
    }

    struct mq_attr attr;
    if (mq_getattr(queue, &attr) == -1) {
        perror("mq_getattr");
        return 1;
    }

    printf("Default max messages in queue: %ld\n", attr.mq_maxmsg);
    printf("Default max message size: %ld bytes\n", attr.mq_msgsize);

    mq_close(queue);
    return 0;
}

