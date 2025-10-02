#include <stdio.h>
#include <string.h>
int main(void){
    char text[]="red,green,blue";
    for (char *tok=strtok(text,","); tok; tok=strtok(NULL,",")) puts(tok);
    return 0;
}
