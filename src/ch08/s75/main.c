#include <stdio.h>
#include <time.h>

#define LOG(fmt, ...) do { \
    time_t now = time(NULL); \
    char buf[20]; \
    strftime(buf, sizeof(buf), "%H:%M:%S", localtime(&now)); \
    fprintf(stderr, "[%s] " fmt "\n", buf, ##__VA_ARGS__); \
} while (0)

int main(void) {
    LOG("Starting program");
    LOG("Loading config");
    LOG("Finished setup");
}
