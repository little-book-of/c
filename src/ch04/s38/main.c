#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry {
    char *key;
    int value;
    struct Entry *next;
} Entry;

typedef struct {
    Entry **buckets;
    size_t size;
} HashTable;

unsigned long hash_string(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

HashTable* create_table(size_t size) {
    HashTable *t = malloc(sizeof(HashTable));
    t->size = size;
    t->buckets = calloc(size, sizeof(Entry*));
    return t;
}

Entry* create_entry(const char *key, int value) {
    Entry *e = malloc(sizeof(Entry));
    e->key = strdup(key);
    e->value = value;
    e->next = NULL;
    return e;
}

void insert(HashTable *t, const char *key, int value) {
    unsigned long index = hash_string(key) % t->size;
    Entry *new_entry = create_entry(key, value);
    new_entry->next = t->buckets[index];
    t->buckets[index] = new_entry;
}

Entry* search(HashTable *t, const char *key) {
    unsigned long index = hash_string(key) % t->size;
    for (Entry *e = t->buckets[index]; e; e = e->next)
        if (strcmp(e->key, key) == 0)
            return e;
    return NULL;
}

void free_table(HashTable *t) {
    for (size_t i = 0; i < t->size; i++) {
        Entry *e = t->buckets[i];
        while (e) {
            Entry *next = e->next;
            free(e->key);
            free(e);
            e = next;
        }
    }
    free(t->buckets);
    free(t);
}

int main(void) {
    HashTable *table = create_table(8);

    insert(table, "apple", 5);
    insert(table, "banana", 7);
    insert(table, "orange", 10);

    Entry *result = search(table, "banana");
    if (result)
        printf("banana = %d\n", result->value);
    else
        printf("Key not found\n");

    free_table(table);
    return 0;
}
