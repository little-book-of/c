#include <stdio.h>
#include <string.h>
int main(void){
    const char *text = "catapult scatter catalog";
    const char *sub  = "cat";
    int cnt=0;
    for (const char *p=text; (p=strstr(p,sub)); p++) cnt++;
    printf("%d\n", cnt); // expected 3
    return 0;
}
