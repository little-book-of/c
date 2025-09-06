#include <stdio.h>
#include <string.h>
void safe_copy(char *dst, size_t n, const char *src){
    if (n==0) return;
    strncpy(dst, src, n-1);
    dst[n-1] = '\0';
}
int main(void){
    char buf[8];
    safe_copy(buf,sizeof buf,"helloworld");
    printf("%s\n", buf);
    return 0;
}
