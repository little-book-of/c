#include <stdio.h>
#include <time.h>
int main(void){
    time_t now = time(NULL);
    struct tm *loc = localtime(&now);
    struct tm *utc = gmtime(&now);
    char a[64], b[64];
    strftime(a,sizeof a,"%Y-%m-%d %H:%M:%S", loc);
    strftime(b,sizeof b,"%Y-%m-%d %H:%M:%S", utc);
    printf("Local: %s\nUTC:   %s\n", a, b);
    return 0;
}
