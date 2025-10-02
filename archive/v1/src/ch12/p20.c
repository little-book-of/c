#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    srand((unsigned)time(NULL));
    int streak=0, tosses=0;
    while(streak<3){
        tosses++;
        if (rand()%2){ puts("Heads"); streak++; }
        else { puts("Tails"); streak=0; }
    }
    printf("tosses=%d\n", tosses);
    return 0;
}
