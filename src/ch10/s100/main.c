// file: tinynotes.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOTE_LEN 256
#define DATA_FILE "notes.bin"

typedef struct {
    int id;
    char text[MAX_NOTE_LEN];
} Note;

static void add_note(const char *msg) {
    FILE *f = fopen(DATA_FILE, "ab");
    if (!f) { perror("open"); exit(1); }

    Note n = {0};
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    n.id = (int)(size / sizeof(Note)) + 1;
    strncpy(n.text, msg, MAX_NOTE_LEN - 1);

    fwrite(&n, sizeof(n), 1, f);
    fclose(f);
    printf("Added note %d: %s\n", n.id, n.text);
}

static void list_notes(void) {
    FILE *f = fopen(DATA_FILE, "rb");
    if (!f) { puts("No notes yet."); return; }

    Note n;
    while (fread(&n, sizeof(n), 1, f) == 1)
        printf("%d: %s\n", n.id, n.text);
    fclose(f);
}

static void delete_all(void) {
    if (remove(DATA_FILE) == 0)
        puts("All notes deleted.");
    else
        puts("No notes to delete.");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        puts("Usage: tinynotes <add|list|clear> [message]");
        return 0;
    }

    if (strcmp(argv[1], "add") == 0 && argc >= 3) {
        add_note(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_notes();
    } else if (strcmp(argv[1], "clear") == 0) {
        delete_all();
    } else {
        puts("Invalid command.");
    }
    return 0;
}
