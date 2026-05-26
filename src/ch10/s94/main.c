// file: kv.c
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>   // Windows: include <winsock2.h> and link Ws2_32
#include <errno.h>

typedef struct {
    FILE *f;
    char *path;
    // simple hash table index
    struct slot { uint64_t off; uint32_t h, klen; } *tab;
    size_t cap, used;
} kv_db;

static uint32_t fnv1a(const unsigned char *s, size_t n) {
    uint32_t h = 2166136261u;
    for (size_t i = 0; i < n; i++) { h ^= s[i]; h *= 16777619u; }
    return h;
}

static size_t next_pow2(size_t n) { size_t p = 1; while (p < n) p <<= 1; return p; }

static int kv_index_put(kv_db *db, const unsigned char *key, uint32_t klen, uint64_t off) {
    if (db->used * 2 >= db->cap) { // grow
        size_t ncap = db->cap ? db->cap * 2 : 1024;
        struct slot *old = db->tab;
        size_t oldcap = db->cap;
        db->tab = calloc(ncap, sizeof(*db->tab));
        if (!db->tab) return -1;
        db->cap = ncap; db->used = 0;
        for (size_t i = 0; i < oldcap; i++) if (old[i].off) {
            // reinsert based on stored key hash and key length
            size_t m = ncap - 1, j = old[i].h & m;
            while (db->tab[j].off) j = (j + 1) & m;
            db->tab[j] = old[i];
            db->used++;
        }
        free(old);
    }
    uint32_t h = fnv1a(key, klen);
    size_t m = db->cap - 1, i = h & m;
    while (db->tab[i].off) {
        if (db->tab[i].h == h && db->tab[i].klen == klen) { db->tab[i].off = off; return 0; }
        i = (i + 1) & m;
    }
    db->tab[i].off = off; db->tab[i].h = h; db->tab[i].klen = klen; db->used++;
    return 0;
}

static long kv_index_find_slot(kv_db *db, const unsigned char *key, uint32_t klen) {
    if (db->cap == 0) return -1;
    uint32_t h = fnv1a(key, klen);
    size_t m = db->cap - 1, i = h & m, steps = 0;
    while (db->tab[i].off && steps <= db->cap) {
        if (db->tab[i].h == h && db->tab[i].klen == klen) return (long)i;
        i = (i + 1) & m; steps++;
    }
    return -1;
}

static int kv_open(kv_db *db, const char *path) {
    memset(db, 0, sizeof(*db));
    db->path = strdup(path);
    db->f = fopen(path, "ab+");
    if (!db->f) return -1;
    fflush(db->f);
    // build index by scanning from start
    FILE *r = fopen(path, "rb");
    if (!r) return -1;
    // start with some capacity
    db->cap = 1024; db->tab = calloc(db->cap, sizeof(*db->tab));
    if (!db->tab) return -1;
    uint64_t off = 0;
    for (;;) {
        uint32_t klen_be, vlen_be;
        if (fread(&klen_be, 4, 1, r) != 1) break;
        if (fread(&vlen_be, 4, 1, r) != 1) break;
        uint32_t klen = ntohl(klen_be), vlen = ntohl(vlen_be);
        unsigned char *k = malloc(klen);
        if (!k) break;
        if (fread(k, 1, klen, r) != klen) { free(k); break; }
        if (fseek(r, vlen, SEEK_CUR) != 0) { free(k); break; }
        kv_index_put(db, k, klen, off);
        free(k);
        off += 8u + klen + vlen;
    }
    fclose(r);
    return 0;
}

static int kv_set(kv_db *db, const unsigned char *key, uint32_t klen,
                  const unsigned char *val, uint32_t vlen) {
    uint32_t klen_be = htonl(klen), vlen_be = htonl(vlen);
    if (fwrite(&klen_be, 4, 1, db->f) != 1) return -1;
    if (fwrite(&vlen_be, 4, 1, db->f) != 1) return -1;
    if (fwrite(key, 1, klen, db->f) != klen) return -1;
    if (fwrite(val, 1, vlen, db->f) != vlen) return -1;
    fflush(db->f); // durability: fsync would be stronger
    // compute offset of the record we just wrote
    long end = ftell(db->f);
    if (end < 0) return -1;
    uint64_t off = (uint64_t)end - (8u + klen + vlen);
    return kv_index_put(db, key, klen, off);
}

static int kv_get(kv_db *db, const unsigned char *key, uint32_t klen,
                  unsigned char **out, uint32_t *outlen) {
    long s = kv_index_find_slot(db, key, klen);
    if (s < 0) return -1;
    uint64_t off = db->tab[s].off;
    if (fseek(db->f, (long)off, SEEK_SET) != 0) return -1;
    uint32_t klen_be, vlen_be;
    if (fread(&klen_be, 4, 1, db->f) != 1) return -1;
    if (fread(&vlen_be, 4, 1, db->f) != 1) return -1;
    uint32_t kL = ntohl(klen_be), vL = ntohl(vlen_be);
    unsigned char *kbuf = malloc(kL);
    if (!kbuf) return -1;
    if (fread(kbuf, 1, kL, db->f) != kL) { free(kbuf); return -1; }
    // confirm key match to be safe
    if (kL != klen || memcmp(kbuf, key, klen) != 0) { free(kbuf); return -1; }
    free(kbuf);
    unsigned char *v = malloc(vL + 1);
    if (!v) return -1;
    if (fread(v, 1, vL, db->f) != vL) { free(v); return -1; }
    v[vL] = 0; // NUL terminate for convenience
    *out = v; *outlen = vL;
    return 0;
}

static void kv_close(kv_db *db) {
    if (!db) return;
    if (db->f) fclose(db->f);
    free(db->tab);
    free(db->path);
}

static void usage(const char *p) {
    fprintf(stderr, "Usage: %s <file> get <key>\n", p);
    fprintf(stderr, "       %s <file> set <key> <value>\n", p);
}

int main(int argc, char **argv) {
    if (argc < 4) { usage(argv[0]); return 1; }
    kv_db db;
    if (kv_open(&db, argv[1]) != 0) { perror("open"); return 1; }

    const char *cmd = argv[2];
    if (strcmp(cmd, "set") == 0) {
        if (argc < 5) { usage(argv[0]); kv_close(&db); return 1; }
        const unsigned char *k = (const unsigned char *)argv[3];
        const unsigned char *v = (const unsigned char *)argv[4];
        if (kv_set(&db, k, (uint32_t)strlen((char*)k), v, (uint32_t)strlen((char*)v)) != 0)
            perror("set");
    } else if (strcmp(cmd, "get") == 0) {
        const unsigned char *k = (const unsigned char *)argv[3];
        unsigned char *out = NULL; uint32_t n = 0;
        if (kv_get(&db, k, (uint32_t)strlen((char*)k), &out, &n) == 0) {
            fwrite(out, 1, n, stdout);
            fputc('\n', stdout);
            free(out);
        } else {
            fprintf(stderr, "not found\n");
        }
    } else {
        usage(argv[0]);
    }

    kv_close(&db);
    return 0;
}
