#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fds[2];
    pipe(fds);

    if (fork() == 0) {
        dup2(fds[1], STDOUT_FILENO);
        close(fds[0]);
        execlp("ls", "ls", NULL);
    }

    if (fork() == 0) {
        dup2(fds[0], STDIN_FILENO);
        close(fds[1]);
        execlp("wc", "wc", "-l", NULL);
    }

    close(fds[0]);
    close(fds[1]);
    wait(NULL);
    wait(NULL);
}
