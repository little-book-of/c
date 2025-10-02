#include <stdio.h>
int main(void){
#if defined(_WIN32)
    puts("Windows");
#elif defined(__linux__)
    puts("Linux");
#else
    puts("Other");
#endif
    return 0;
}
