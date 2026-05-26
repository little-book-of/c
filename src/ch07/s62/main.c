#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char *argv[] = {"ls", "-1", NULL};
    pid_t pid = fork();

    if (pid == 0) {
        execvp(argv[0], argv);
        perror("exec failed");
    } else {
        wait(NULL);
        printf("Command finished\n");
    }
}
