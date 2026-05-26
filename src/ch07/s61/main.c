#include <unistd.h>

int main(void) {
    const char msg[] = "Hello via system call\n";
    write(1, msg, sizeof(msg) - 1);  // 1 = STDOUT
    _exit(0);
}
