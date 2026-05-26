#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#define SLEEP(ms) Sleep(ms)
#else
#include <unistd.h>
#define SLEEP(ms) usleep((ms) * 1000)
#endif

#define THREADS 4
#define ITERATIONS 250000

atomic_int counter = 0;

void* worker(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < ITERATIONS; i++) {
        atomic_fetch_add(&counter, 1);
        if (i % 100000 == 0 && id == 0)
            SLEEP(1);
    }
    return NULL;
}

double now(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

int main(void) {
    pthread_t threads[THREADS];
    int ids[THREADS];
    double start = now();

    for (int i = 0; i < THREADS; i++) {
        ids[i] = i;
        if (pthread_create(&threads[i], NULL, worker, &ids[i]) != 0) {
            perror("pthread_create failed");
            return 1;
        }
    }

    for (int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);

    double end = now();
    printf("Counter = %d (expected %d)\n", counter, THREADS * ITERATIONS);
    printf("Elapsed time: %.3f seconds\n", end - start);
    return 0;
}
