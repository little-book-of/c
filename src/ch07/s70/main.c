#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>

void sigint_handler(int sig) {
    printf("\n$ ");
    fflush(stdout);
}

int main(void) {
    signal(SIGINT, sigint_handler);
    char input[1024];

    while (1) {
        printf("$ ");
        fflush(stdout);
        if (!fgets(input, sizeof(input), stdin)) break;
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "exit") == 0) break;

        char *args[64];
        int i = 0;
        char *token = strtok(input, " ");
        while (token) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        pid_t pid = fork();
        if (pid == 0) {
            for (int j = 0; args[j]; j++) {
                if (strcmp(args[j], ">") == 0) {
                    int fd = open(args[j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                    dup2(fd, STDOUT_FILENO);
                    close(fd);
                    args[j] = NULL;
                } else if (strcmp(args[j], "<") == 0) {
                    int fd = open(args[j + 1], O_RDONLY);
                    dup2(fd, STDIN_FILENO);
                    close(fd);
                    args[j] = NULL;
                }
            }
            execvp(args[0], args);
            perror("execvp");
            exit(1);
        } else if (pid > 0) {
            wait(NULL);
        }
    }

    printf("Exiting shell.\n");
    return 0;
}
