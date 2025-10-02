#include <stdio.h>
#include <time.h>
int main(void){
    int y,m,d; if (scanf("%d %d %d",&y,&m,&d)!=3) return 0;
    struct tm t = {0};
    t.tm_year = y - 1900; t.tm_mon = m - 1; t.tm_mday = d;
    if (mktime(&t) == (time_t)-1) return 0;
    const char* wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
    printf("%s\n", wday[t.tm_wday]);
    return 0;
}
