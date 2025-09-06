#include <stdio.h>
#include <time.h>

static void log_msg(const char *level, const char *msg) {
    FILE *log = fopen("app.log", "a");
    if (!log) return;
    time_t t = time(NULL); char *ts = ctime(&t); if (ts) ts[24] = '\0';
    fprintf(log, "[%s] %s: %s\n", ts ? ts : "unknown-time", level, msg);
    fclose(log);
}
static void log_info(const char *m){ log_msg("INFO",  m); }
static void log_warn(const char *m){ log_msg("WARN",  m); }
static void log_error(const char *m){ log_msg("ERROR", m); }

int main(void) {
    log_info("start");
    log_warn("low disk");
    log_error("failed to connect");
    return 0;
}
