#include <signal.h>
#include <stdio.h>
#include <unistd.h>

volatile sig_atomic_t running = 1;

void stop(int sig) {
    running = 0;
}

int main(void) {
    signal(SIGINT, stop);
    printf("Server running. Press Ctrl+C to stop.\n");

    while (running) {
        printf("Handling request...\n");
        sleep(1);
    }

    printf("Server shutting down cleanly.\n");
}
