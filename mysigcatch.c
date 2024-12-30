#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig_number) {
    printf("\nSIGINT signal caught!\n");
    exit(0);
}

int main() {
    // Register the signal handler for SIGINT
    signal(SIGINT, signal_handler);

    printf("Press Ctrl+C to send SIGINT and catch the signal.\n");
    // Infinite loop to keep the program running until SIGINT is caught
    while (1) {
        // busy wait or do something else
    }
    return 0;
}
