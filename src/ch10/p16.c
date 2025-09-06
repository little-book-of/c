#include <stdio.h>
#include <string.h>
#include <time.h>

static void log_msg(const char *level, const char *msg) {
    FILE *log = fopen("app.log", "a");
    if (!log) return;
    time_t t = time(NULL); char *ts = ctime(&t); if (ts) ts[24] = '\0';
    fprintf(log, "[%s] %s: %s\n", ts ? ts : "unknown-time", level, msg);
    fclose(log);
}

int main(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[1], "--clear") == 0) {
        FILE *f = fopen("app.log", "w");
        if (!f) { perror("app.log"); return 1; }
        fclose(f);
    }
    log_msg("INFO", "program run");
    return 0;
}
