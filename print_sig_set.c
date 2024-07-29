#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void print_signal_set(const sigset_t *set) {
    for (int i = 1; i < NSIG; i++) {
        if (sigismember(set, i)) {
            printf("Signal %d is blocked\n", i);
        }
    }
}

int main() {
    sigset_t sigset;

    // Retrieve the current signal mask
    if (sigprocmask(SIG_BLOCK, NULL, &sigset) == -1) {
        perror("sigprocmask");
        exit(EXIT_FAILURE);
    }

    // Print the signals in the signal set
    print_signal_set(&sigset);

    return 0;
}

