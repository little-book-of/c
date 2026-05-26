#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>

typedef enum { INFO, WARN, ERROR } LogLevel;

const char *level_to_string(LogLevel level) {
    switch (level) {
        case INFO:  return "INFO";
        case WARN:  return "WARN";
        case ERROR: return "ERROR";
        default:    return "UNKNOWN";
    }
}

void write_log(FILE *fp, LogLevel level, const char *fmt, ...) {
    if (!fp) return;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    char timebuf[32];
    strftime(timebuf, sizeof(timebuf), "%Y-%m-%d %H:%M:%S", tm_info);

    va_list args;
    va_start(args, fmt);
    fprintf(fp, "[%s] [%s] ", timebuf, level_to_string(level));
    vfprintf(fp, fmt, args);
    fprintf(fp, "\n");
    fflush(fp);
    va_end(args);
}

int main(void) {
    FILE *logfp = fopen("system.log", "a");
    if (!logfp) {
        perror("Cannot open log file");
        return 1;
    }

    write_log(logfp, INFO,  "System started");
    write_log(logfp, WARN,  "Low disk space on /dev/sda1");
    write_log(logfp, ERROR, "Failed to connect to database");
    write_log(logfp, INFO,  "Shutdown complete");

    fclose(logfp);
    return 0;
}
