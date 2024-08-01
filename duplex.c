#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    int parentToChild[2]; // Pipe for parent to child communication
    int childToParent[2]; // Pipe for child to parent communication

    if (pipe(parentToChild) == -1 || pipe(childToParent) == -1) {
        perror("Error creating pipes");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Error forking process");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Child process
        close(parentToChild[1]); // Close write end of parent-to-child pipe
        close(childToParent[0]); // Close read end of child-to-parent pipe
        char message_from_parent[100];
        read(parentToChild[0], message_from_parent, sizeof(message_from_parent));
        printf("Child received: %s\n", message_from_parent);
        char message_to_parent[] = "Hello from child!";
        write(childToParent[1], message_to_parent, sizeof(message_to_parent));
        close(parentToChild[0]);
        close(childToParent[1]);
    } else {
        // Parent process
        close(parentToChild[0]); // Close read end of parent-to-child pipe
        close(childToParent[1]); // Close write end of child-to-parent pipe

        char message_to_child[] = "Hello from parent!";
        write(parentToChild[1], message_to_child, sizeof(message_to_child));

        char message_from_child[100];
        read(childToParent[0], message_from_child, sizeof(message_from_child));
        printf("Parent received: %s\n", message_from_child);

        close(parentToChild[1]);
        close(childToParent[0]);
    }
    return 0;
}
