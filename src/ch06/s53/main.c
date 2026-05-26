#include <stdio.h>

int main(void) {
#ifdef _WIN32
    printf("Running on Windows\n");
#elif __linux__
    printf("Running on Linux\n");
#elif __APPLE__
    printf("Running on macOS\n");
#else
    printf("Unknown platform\n");
#endif
    return 0;
}
