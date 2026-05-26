#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int src = open("source.txt", O_RDONLY);
    int dst = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (src == -1 || dst == -1) {
        perror("open failed");
        return 1;
    }

    char buf[256];
    ssize_t n;
    while ((n = read(src, buf, sizeof(buf))) > 0)
        write(dst, buf, n);

    close(src);
    close(dst);
    return 0;
}
