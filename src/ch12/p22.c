#include <stdio.h>
#include <string.h>
int main(void){
    char buf[32] = "Hello";
    strncat(buf, " ", sizeof buf - strlen(buf) - 1);
    strncat(buf, "World", sizeof buf - strlen(buf) - 1);
    puts(buf);
    return 0;
}
