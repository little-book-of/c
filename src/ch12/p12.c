#include <stdio.h>
#include <time.h>
int main(void){
    time_t now = time(NULL);
    struct tm *loc = localtime(&now);
    char buf[128];
    strftime(buf,sizeof buf,"%A, %B %d, %Y", loc);
    puts(buf);
    return 0;
}
