#include <stdio.h>
#include <time.h>

static void log_msg(const char *level, const char *msg) {
    FILE *log = fopen("app.log", "a");
    if (!log) return;
    time_t t = time(NULL); char *ts = ctime(&t); if (ts) ts[24] = '\0';
    fprintf(log, "[%s] %s: %s\n", ts ? ts : "unknown-time", level, msg);
    fflush(log);                         // ensure on disk
    fclose(log);
}

int main(void) {
    log_msg("INFO", "flushed");
    return 0;
}
