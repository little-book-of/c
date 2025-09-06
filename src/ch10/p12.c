#include <stdio.h>
#include <time.h>

static void log_msg(const char *level, const char *msg) {
    FILE *log = fopen("app.log", "a");
    if (!log) return;
    time_t t = time(NULL);
    char *ts = ctime(&t);              // "Www Mmm dd hh:mm:ss yyyy\n"
    if (ts) ts[24] = '\0';             // drop '\n' at pos 24
    fprintf(log, "[%s] %s: %s\n", ts ? ts : "unknown-time", level, msg);
    fclose(log);
}

int main(void) {
    log_msg("INFO", "Program started");
    log_msg("ERROR", "Something happened");
    return 0;
}
