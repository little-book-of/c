#include <stdio.h>
#include <string.h>
int main(void){
    char buf[256];
    if (fgets(buf,sizeof buf,stdin)){
        size_t n = strlen(buf);
        printf("%s", buf);
        printf("len=%zu\n", n);
    }
    return 0;
}
