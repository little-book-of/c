#include <stdio.h>
#include <time.h>
static void timestamp(void){
    time_t now = time(NULL);
    struct tm *loc = localtime(&now);
    char buf[32];
    strftime(buf,sizeof buf,"%Y-%m-%d %H:%M:%S", loc);
    printf("[%s]", buf);
}
int main(void){
    timestamp(); puts(" example log message");
    return 0;
}
