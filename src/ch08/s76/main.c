#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
}

void fill_random(int *arr, int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

int main(void) {
    int *arr = malloc(N * sizeof(int));
    fill_random(arr, N);
    bubble_sort(arr, N);
    free(arr);
}
