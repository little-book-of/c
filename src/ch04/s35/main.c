#include <stdio.h>

enum Status {
    SUCCESS = 0,
    WARNING = 1,
    ERROR = 2
};

const char* status_to_string(enum Status s) {
    switch (s) {
        case SUCCESS: return "Success";
        case WARNING: return "Warning";
        case ERROR:   return "Error";
        default:      return "Unknown";
    }
}

int main(void) {
    enum Status s = WARNING;
    printf("Status: %s (%d)\n", status_to_string(s), s);
    return 0;
}
