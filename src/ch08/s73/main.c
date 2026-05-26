#include <assert.h>
#include <stdio.h>

#define MAX 5

int safe_get(int arr[], int n, int i) {
    assert(i >= 0 && i < n);
    return arr[i];
}

int main(void) {
    int nums[MAX] = {1, 2, 3, 4, 5};
    printf("%d\n", safe_get(nums, MAX, 2));  // OK
    printf("%d\n", safe_get(nums, MAX, 10)); // triggers assertion
}
