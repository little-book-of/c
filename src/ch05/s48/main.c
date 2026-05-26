/* Section 48: Reading Configuration Files — full self-contained example. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 128

typedef struct {
    int port;
    char host[64];
    int max_clients;
    char log_file[64];
} Config;

void load_config(const char *filename, Config *cfg) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;  /* silently keep defaults if file missing */

    char line[MAX_LINE];
    while (fgets(line, sizeof(line), fp)) {
        line[strcspn(line, "\n")] = '\0';
        if (line[0] == '#' || strlen(line) == 0) continue;

        char key[64], value[64];
        if (sscanf(line, "%63[^=]=%63s", key, value) == 2) {
            if      (strcmp(key, "port")        == 0) cfg->port        = atoi(value);
            else if (strcmp(key, "host")        == 0) strncpy(cfg->host,     value, sizeof(cfg->host) - 1);
            else if (strcmp(key, "max_clients") == 0) cfg->max_clients = atoi(value);
            else if (strcmp(key, "log_file")    == 0) strncpy(cfg->log_file, value, sizeof(cfg->log_file) - 1);
        }
    }
    fclose(fp);
}

int main(void) {
    /* Sensible defaults — survive a missing or partial config file */
    Config cfg = {
        .port = 8080,
        .max_clients = 100,
    };
    strncpy(cfg.host, "localhost", sizeof(cfg.host) - 1);
    strncpy(cfg.log_file, "server.log", sizeof(cfg.log_file) - 1);

    load_config("config.txt", &cfg);

    printf("Host:        %s\n", cfg.host);
    printf("Port:        %d\n", cfg.port);
    printf("MaxClients:  %d\n", cfg.max_clients);
    printf("LogFile:     %s\n", cfg.log_file);
    return 0;
}
