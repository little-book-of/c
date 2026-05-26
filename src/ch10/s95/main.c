#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    unsigned char *base;
    size_t capacity;
    size_t offset;
} Arena;

Arena *arena_create(size_t capacity) {
    Arena *a = malloc(sizeof(Arena));
    if (!a) return NULL;
    a->base = malloc(capacity);
    if (!a->base) { free(a); return NULL; }
    a->capacity = capacity;
    a->offset = 0;
    return a;
}

void *arena_alloc(Arena *a, size_t size) {
    if (a->offset + size > a->capacity) return NULL;
    void *ptr = a->base + a->offset;
    a->offset += size;
    return ptr;
}

void arena_reset(Arena *a) { a->offset = 0; }

void arena_free(Arena *a) { free(a->base); free(a); }

int main(void) {
    Arena *arena = arena_create(4096);
    if (!arena) { fprintf(stderr, "OOM\n"); return 1; }

    int *nums = arena_alloc(arena, 10 * sizeof(int));
    for (int i = 0; i < 10; i++) nums[i] = i * i;
    for (int i = 0; i < 10; i++) printf("%d ", nums[i]);
    printf("\n");

    arena_reset(arena);
    printf("Arena reset. offset = %zu\n", arena->offset);

    arena_free(arena);
    return 0;
}
