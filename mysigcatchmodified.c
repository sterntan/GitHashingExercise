#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static int count_sigint = 0;

void custom_handler(int sig_number) {
    count_sigint++;
    printf("\nSignal number %d caught! This is catch number %d.\n", sig_number, count_sigint);

    if (count_sigint == 2) {
        // Restore default signal handler after catching twice
        signal(SIGINT, SIG_DFL);
        printf("Default SIGINT behavior restored. Next Ctrl+C will terminate immediately.\n");
    }
}

int main() {
    // Register the custom signal handler for SIGINT
    signal(SIGINT, custom_handler);
    printf("Press Ctrl+C to send SIGINT.\n");

    while (1) {
        // busy wait or perform other tasks
    }
    return 0;
}
