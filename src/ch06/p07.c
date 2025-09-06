#include <stdio.h>

int main(void) {
    int arr[] = {1,2,3,4,5};
    int n = (int)(sizeof(arr)/sizeof(arr[0]));
    long long s = 0;
    for (int i = 0; i < n; i++) s += (long long)arr[i]*arr[i];
    printf("%lld\n", s);
    return 0;
}
