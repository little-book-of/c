#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    int fd = open("bigfile.txt", O_RDONLY);
    struct stat st;
    fstat(fd, &st);

    char *data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    size_t lines = 0;

    for (size_t i = 0; i < st.st_size; i++)
        if (data[i] == '\n') lines++;

    printf("Lines: %zu\n", lines);
    munmap(data, st.st_size);
    close(fd);
}
