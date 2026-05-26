#include <pthread.h>
#include <stdio.h>

#define N 4

int partial[4];

void* compute(void* arg) {
    int id = *(int*)arg;
    int start = id * 25;
    int sum = 0;
    for (int i = start; i < start + 25; i++)
        sum += i;
    partial[id] = sum;
    return NULL;
}

int main(void) {
    pthread_t threads[N];
    int ids[N];
    for (int i = 0; i < N; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, compute, &ids[i]);
    }

    int total = 0;
    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
        total += partial[i];
    }

    printf("Total sum = %d\n", total);
}
